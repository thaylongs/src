/***************************************************
 ** ViSUS Visualization Project                    **
 ** Copyright (c) 2010 University of Utah          **
 ** Scientific Computing and Imaging Institute     **
 ** 72 S Central Campus Drive, Room 3750           **
 ** Salt Lake City, UT 84112                       **
 **                                                **
 ** For information about this project see:        **
 ** http://www.pascucci.org/visus/                 **
 **                                                **
 **      or contact: pascucci@sci.utah.edu         **
 **                                                **
 ****************************************************/

#include <cstdarg>
#include <string>
#include "pidx_idx_io.h"
#include "data_handle/PIDX_data_types.h"

typedef std::string String;

bool debug = true;

static int process_count = 1, rank = 0;

static PIDX_point global_size, local_offset, local_size;
static PIDX_file pidx_file;
static PIDX_access pidx_access;
static String input_filename;

#if PIDX_HAVE_MPI
static MPI_Comm NEW_COMM_WORLD;
#endif

static void terminate(int out)
{
#if PIDX_HAVE_MPI
  MPI_Abort(NEW_COMM_WORLD, out);
#else
//  exit(out); - FIX ME CAN NOT EXIT
#endif
}

static void terminate_with_error_msg(const char *format, ...)
{
  va_list arg_ptr;
  va_start(arg_ptr, format);
  vfprintf(stderr, format, arg_ptr);
  va_end(arg_ptr);
  terminate(-1);
}

static void init_mpi()
{

#if PIDX_HAVE_MPI
  int mpi_init;
  MPI_Initialized(&mpi_init);
  
  if (!mpi_init){
    if (MPI_Init(NULL, NULL) != MPI_SUCCESS)
      terminate_with_error_msg("ERROR: MPI_Init error\n");
  }
  MPI_Comm_dup(MPI_COMM_WORLD, &NEW_COMM_WORLD);
  if (MPI_Comm_size(NEW_COMM_WORLD, &process_count) != MPI_SUCCESS)
    terminate_with_error_msg("ERROR: MPI_Comm_size error\n");
  if (MPI_Comm_rank(NEW_COMM_WORLD, &rank) != MPI_SUCCESS)
    terminate_with_error_msg("ERROR: MPI_Comm_rank error\n");
#endif
}

VisitIDXIO::DTypes convertType(PIDX_data_type intype){
  
  if(strcmp(intype,INT8) == 0)
    return VisitIDXIO::IDX_INT8;
  else if(strcmp(intype,UINT8) == 0)
    return VisitIDXIO::IDX_UINT8;
  else if(strcmp(intype, INT16)==0)
    return VisitIDXIO::IDX_INT16;
  else if(strcmp(intype, UINT16)==0)
    return VisitIDXIO::IDX_UINT16;
  else if(strcmp(intype, INT32)==0)
    return VisitIDXIO::IDX_INT32;
  else if(strcmp(intype, UINT32)==0)
    return VisitIDXIO::IDX_UINT32;
  else if(strcmp(intype, INT64)==0)
    return VisitIDXIO::IDX_INT64;
  else if(strcmp(intype, UINT64)==0)
    return VisitIDXIO::IDX_UINT64;
  else if(strcmp(intype,FLOAT32)==0)
    return VisitIDXIO::IDX_FLOAT32;
  else if(strcmp(intype, FLOAT64)==0){
    return VisitIDXIO::IDX_FLOAT64;
  }
  
  fprintf(stderr, "Type not found for PIDX\n");
  
}


PIDXIO::~PIDXIO(){
  if(debug)
    printf("Terminate PIDXIO...\n");
 // terminate(0);
}

bool PIDXIO::openDataset(const String filename){
  
  if(debug)
    printf("-----PIDXIO openDataset\n");
  
  init_mpi();
  
  debug = debug && rank == 0;

  int ret;
  int variable_count;

  PIDX_create_access(&pidx_access);
#if PIDX_HAVE_MPI
  PIDX_set_mpi_access(pidx_access, MPI_COMM_WORLD);
#endif
  
  input_filename = filename;
  
  ret = PIDX_file_open(filename.c_str(), PIDX_MODE_RDONLY, pidx_access, &pidx_file);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_file_open");
  
  if(use_raw)
    PIDX_enable_raw_io(pidx_file);
  
  ret = PIDX_get_dims(pidx_file, global_size);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_set_dims");
  
  (global_size[2] > 1) ? dims = 3 : dims = 2;
  
  for(int i=0; i < dims; i++){
    logic_box.p1[i] = 0;
    logic_box.p2[i] = global_size[i];//-1;
  }
  
  if(debug)
    printf("dims %lld %lld %lld\n", global_size[0],global_size[1],global_size[2]);
  
  ret = PIDX_get_variable_count(pidx_file, &variable_count);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_set_variable_count");
  
  int first_tstep = 0, last_tstep = 0;
  ret = PIDX_get_first_tstep(pidx_file, &first_tstep);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_get_first_tstep");
  ret = PIDX_get_last_tstep(pidx_file, &last_tstep);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_get_last_tstep");

#if PIDX_HAVE_MPI  
  MPI_Bcast(&first_tstep, 1, MPI_INT, 0, NEW_COMM_WORLD);
  MPI_Bcast(&last_tstep, 1, MPI_INT, 0, NEW_COMM_WORLD);
#endif
  
  tsteps.clear();
  for(int i=first_tstep; i <= last_tstep; i++)
    tsteps.push_back(i);
  
  ntimesteps = tsteps.size();

  if(debug)
    printf("time size %lu\n", tsteps.size());
 /*
  int res[2];
  ret = PIDX_get_resolution(pidx_file, res);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_get_first_tstep");
  
  max_resolution = res[1];
  
  printf("max res %d\n", max_resolution);
  */
  if(debug)
    printf("%d variables\n", variable_count);
  
  PIDX_variable* variable = (PIDX_variable*)malloc(sizeof(*variable) * variable_count);
  memset(variable, 0, sizeof(*variable) * variable_count);
  
  fields.clear();
  for (int var = 0; var < variable_count; var++)
  {
    ret = PIDX_get_next_variable(pidx_file, &variable[var]);
    if (ret != PIDX_success) terminate_with_error_msg("PIDX_get_next_variable");
    
    int values_per_sample = variable[var]->values_per_sample;
    
    int bits_per_sample = 0;
    ret = PIDX_default_bits_per_datatype(variable[var]->type_name, &bits_per_sample);
    if (ret != PIDX_success)  terminate_with_error_msg("PIDX_default_bytes_per_datatype");
    
  //  if(rank == 0){    
      VisitIDXIO::Field my_field;

      my_field.ncomponents = atoi((const char*)(variable[var]->type_name)); // trick to resolve type easilty and get ncomponents
      char typetocheck[32];
      strncpy(typetocheck, variable[var]->type_name, 32);
      typetocheck[0] = '1';
      my_field.type = convertType(typetocheck);
      
      my_field.isVector = my_field.ncomponents > 1 ? true : false;
      
      if(debug)
        printf("\t variable %s idx %d values per sample %d bits per sample %d ncomp %d\n", variable[var]->var_name, var, values_per_sample, bits_per_sample, my_field.ncomponents);

      char *name = new char[256];
      strcpy(name, variable[var]->var_name);
      my_field.name = name;
      
      fields.push_back(my_field);
      
      ret = PIDX_read_next_variable(pidx_file, variable[var]);
      if (ret != PIDX_success)  terminate_with_error_msg("PIDX_read_next_variable");
      
 //   }
  
  }
  
  ret = PIDX_reset_variable_counter(pidx_file);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_reset_variable_counter");
  
//  printf("reset variable count\n!");
  /*ret = PIDX_close(pidx_file);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_close");
  printf("PIDX close\n!");
  */
  
  ret = PIDX_close_access(pidx_access);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_close_access");
  //printf("PIDX close access\n!");
  
  free(variable);
  
  return true;
  
}

unsigned char* PIDXIO::getData(const VisitIDXIO::Box box, const int timestate, const char* varname){
  if(debug)
    printf("-----PIDXIO getData %d \n", rank);

// fake data
  // void *datatemp = malloc(sizeof(double) * global_size[0] * global_size[1] * global_size[2]);
  // memset(datatemp, 10, sizeof(double) * global_size[0] * global_size[1] * global_size[2]);
  // return (unsigned char*)datatemp;
  
  int ret = 0;
  
  int variable_index = -1;
  
  for(int i=0; i<fields.size(); i++){
    if(strcmp(fields[i].name.c_str(),varname) == 0 && strlen(fields[i].name.c_str()) == strlen(varname))
      variable_index = i;
  }
  
  if(variable_index < 0){
    fprintf(stderr,"No variable %s found\n", varname);
    return NULL;
  }
  
  if(debug)
    printf("var index %d\n", variable_index);
  
  curr_field = fields[variable_index];
/*  
#ifdef PARALLEL
  local_size[0] = 32;
  local_size[1] = 32;
  local_size[2] = 32;
  local_size[3] = 1;
  local_size[4] = 1;
  
  int sub_div[3];
  sub_div[0] = (global_size[0] / local_size[0]);
  sub_div[1] = (global_size[1] / local_size[1]);
  sub_div[2] = (global_size[2] / local_size[2]);
  
  local_offset[2] = (rank / (sub_div[0] * sub_div[1])) * local_size[2];
  int slice = rank % (sub_div[0] * sub_div[1]);
  local_offset[1] = (slice / sub_div[0]) * local_size[1];
  local_offset[0] = (slice % sub_div[0]) * local_size[0];
  
#else*/
  for(int i=0; i< dims; i++){
      local_size[i] = box.p2[i] - box.p1[i] + 1;
      local_offset[i] = box.p1[i];
  }
//#endif

  local_size[3] = 1;
  local_size[4] = 1;
  local_offset[3] = 0;
  local_offset[4] = 0;
  
  if(debug)
    printf("local box %lld %lld %lld size %lld %lld %lld time %d\n", local_offset[0],local_offset[1],local_offset[2], local_size[0],local_size[1],local_size[2], timestate);
  
  PIDX_create_access(&pidx_access);
#if PIDX_HAVE_MPI
  PIDX_set_mpi_access(pidx_access, MPI_COMM_WORLD);
#endif

  ret = PIDX_file_open(input_filename.c_str(), PIDX_MODE_RDONLY, pidx_access, &pidx_file);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_file_create");

  int variable_count,time_step_count;
  ret = PIDX_get_dims(pidx_file, global_size);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_set_dims");
  
  ret = PIDX_get_variable_count(pidx_file, &variable_count);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_set_variable_count");
  
  if (variable_index >= variable_count) terminate_with_error_msg("Variable index more than variable count\n");
  
  // set RAW for now
  if(use_raw)
   PIDX_enable_raw_io(pidx_file);

  ret = PIDX_set_current_time_step(pidx_file, timestate);
  if (ret != PIDX_success) {
    fprintf(stderr, "ERROR: PIDX_set_current_time_step\n");
    //terminate_with_error_msg("PIDX_set_current_time_step");
    return NULL;
  }
//   PIDX_debug_output(pidx_file);
  PIDX_variable variable;
  
  ret = PIDX_set_current_variable_index(pidx_file, variable_index);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_set_current_variable_index");

  ret = PIDX_get_current_variable(pidx_file, &variable);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_get_current_variable");

  int bits_per_sample = 0;
  ret = PIDX_default_bits_per_datatype(variable->type_name, &bits_per_sample);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_default_bytes_per_datatype");
  
  if(debug)
    printf("reading %lldx%lldx%lld bps %d\n", local_size[0], local_size[1], local_size[2], bits_per_sample);
  
  int v_per_sample = 0;
  PIDX_values_per_datatype(variable->type_name, &v_per_sample, &bits_per_sample);

  void *data = malloc((bits_per_sample/8) * local_size[0] * local_size[1] * local_size[2]  * v_per_sample);//variable->values_per_sample);
  memset(data, 0, (bits_per_sample/8) * local_size[0] * local_size[1] * local_size[2]  * v_per_sample);//variable->values_per_sample);

  ret = PIDX_variable_read_data_layout(variable, local_offset, local_size, data, PIDX_row_major);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_variable_read_data_layout");
  
  ret = PIDX_close(pidx_file);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_close");

  ret = PIDX_close_access(pidx_access);
  if (ret != PIDX_success)  terminate_with_error_msg("PIDX_close_access");

  return (unsigned char*)data;

}
