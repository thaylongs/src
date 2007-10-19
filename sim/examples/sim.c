/*****************************************************************************
*
* Copyright (c) 2000 - 2007, The Regents of the University of California
* Produced at the Lawrence Livermore National Laboratory
* All rights reserved.
*
* This file is part of VisIt. For details, see http://www.llnl.gov/visit/. The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or materials provided with the distribution.
*  - Neither the name of the UC/LLNL nor  the names of its contributors may be
*    used to  endorse or  promote products derived from  this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED.  IN  NO  EVENT  SHALL  THE  REGENTS  OF  THE  UNIVERSITY OF
* CALIFORNIA, THE U.S.  DEPARTMENT  OF  ENERGY OR CONTRIBUTORS BE  LIABLE  FOR
* ANY  DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

/*****************************************************************************
* Programmer:  Jeremy Meredith
* Creation:    July 10, 2003
*
* Modifications:
*   Jeremy Meredith, Wed Jan 14 12:23:02 PST 2004
*   Made it work with the VisIt library.
*
*   Jeremy Meredith, Tue Mar 30 18:12:12 PDT 2004
*   Some major preliminary productization.
*
*   Jeremy Meredith, Wed Aug 25 13:36:11 PDT 2004
*   Getting closer.  Some hefty changes -- refactored some things
*   into a separate file that can be included by other simulations.
*
*   Jeremy Meredith, Mon Nov  1 17:27:54 PST 2004
*   Made it work in parallel, at least with two processors.
*
*   Jeremy Meredith, Thu Mar 17 12:59:15 PST 2005
*   Changed it to use float values.
*
*   Jeremy Meredith, Mon Apr  4 16:44:29 PDT 2005
*   Split command parsing out into a separate function.
*   Added more options to the sim file dumping.
*
*   Jeremy Meredith, Wed May 25 14:16:00 PDT 2005
*   Major reorg in the main routine because I drastically updated
*   VisItControlInterface_V1.
*
*   Shelly Prevost, Jan 28. 2006
*   Added code to respond to the larger number of VisIt commands that are
*   reflected back due to interface updates generated by the simulations.
*
*   Shelly prevost, Tue Sep 12 10:56:07 PDT 2006
*   Added up funtion documentation
*
******************************************************************************/
#include "sim.h"
#include "SimHelperFunc.h"
#include "VisItControlInterface_V1.h"
#include "UI_Connection.h"


#include <stdlib.h>
#include <stdio.h>

#include <dlfcn.h>
#include <errno.h>
#include <signal.h> /* for signal handling (may go away)   */
#include <string.h> /* for strdup (may go away)            */
#include <unistd.h> /* for execv (may go away)             */
#include <math.h>
#include <time.h>

#ifdef PARALLEL
#include <mpi.h>
#endif

int par_rank = 0;
int par_size = 1;

#define TRUE 1
#define FALSE 0
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX3(a,b,c) MAX(a,MAX(b,c))

int runflag = 0;
int quitflag = 0;

int cycle = 0;

int p_nx = 10;
int p_ny = 10;
int p_nz = 10;
float *p_xcoords;
float *p_ycoords;
float *p_zcoords;
float *p_zvalues;
float *p_nvalues;

int numdomains = 1;

/*****************************************************************************
* Function: testSlot family of functions
*
* Purpose:
*   called as a callback when a UI in the VisIt Simulation window is changed.
*
* Arguments:
*   cmd:  The command string passed from a signal generated
*
* Programmer: Shelly Prevost
* Creation:   Tue Sep 12 10:56:07 PDT 2006
*
* Modifications:
*
*****************************************************************************/
void
testSlot(char *cmd)
{
    printf( "sim >>>>  inside simulation pushButton code callback slot1.... \n");
}

void testSlot2(char *cmd)
{
    printf( "sim >>>>  inside simulation code callback slot2 .... \n");
}

void apply(char *cmd)
{
    printf( "sim >>>>  inside simulation apply code callback  .... \n");
}

void valueChanged(char *cmd)
{
    printf( "sim >>>>  inside simulation valueChanged code callback .... \n");
}

void currentChanged(char *cmd)
{
    printf( "sim >>>>  inside simulation currentChanged code callback .... \n");
}

void alert(char *cmd)
{
    printf( "sim >>>>  ALERT ALERT ALERT .... \n");
}

void enableStripChartCallback(char *cmd)
{
    printf( "sim >>>>  ALERT ALERT ALERT .... \n");
}

/*****************************************************************************
* Function: visit_broadcast_int_callback
*
* Purpose:
*   In a parallel situation the commands have to be sent to all the engines.
*
* Arguments:
*   value:
*   sender:
*
* Programmer: Shelly Prevost
* Creation:   Tue Sep 12 10:56:07 PDT 2006
*
* Modifications:
*
*****************************************************************************/
#ifdef PARALLEL
static int
visit_broadcast_int_callback(int *value, int sender)
{
    return MPI_Bcast(value, 1, MPI_INT, sender, MPI_COMM_WORLD) ;
}

/*****************************************************************************
* Function: visit_broadcast_string_callback
*
* Purpose:
*   brodcast string to all engines
*
* Arguments:
*
* Programmer: Shelly Prevost
* Creation:   Tue Sep 12 10:56:07 PDT 2006
*
* Modifications:
*
*****************************************************************************/
static int
visit_broadcast_string_callback(char *str, int len, int sender)
{
    return MPI_Bcast(str, len, MPI_CHAR, sender, MPI_COMM_WORLD) ;
}
#endif


/*****************************************************************************
* Function: InitializeVariables
*
* Purpose:
*   Do some general purpose setup for that test data
*
* Arguments:
*
* Programmer: Shelly Prevost
* Creation:   Tue Sep 12 10:56:07 PDT 2006
*
* Modifications:
*
*****************************************************************************/
void
InitializeVariables()
{
    int i;
    p_xcoords = malloc(sizeof(float) * p_nx);
    p_ycoords = malloc(sizeof(float) * p_ny);
    p_zcoords = malloc(sizeof(float) * p_nz);
    p_zvalues = malloc(sizeof(float) * (p_nx-1)*(p_ny-1)*(p_nz-1));
    p_nvalues = malloc(sizeof(float) * p_nx*p_ny*p_nz);
    for (i=0; i<p_nx; i++)
    {
        int ii = (i + (p_nx-1)*par_rank);
        p_xcoords[i] = ii*2.0;
    }
    for (i=0; i<p_ny; i++)
    {
        p_ycoords[i] = i*1.5;
    }
    for (i=0; i<p_nz; i++)
    {
        p_zcoords[i] = i*1.0;
    }
    for (i=0; i<(p_nx-1)*(p_ny-1)*(p_nz-1); i++)
    {
        p_zvalues[i] = i*1.0;
    }
    for (i=0; i<p_nx*p_ny*p_nz; i++)
    {
        p_nvalues[i] = i*1.0;
    }

    numdomains = par_size;
}

/*****************************************************************************
* Function: RunSingleCycle
*
* Purpose:
*   Run one cycle of the simulation
*
* Arguments:
*
* Programmer: Shelly Prevost
* Creation:   Tue Sep 12 10:56:07 PDT 20065
*
* Modifications:
*
*****************************************************************************/
void
RunSingleCycle()
{
    int i;

    time_t starttime = time(NULL);
    while (time(NULL) == starttime)
    {
        /* Wait */
    }
    /* If the cycle times are long you may want
       to check for commands from the Visit program
       periodically.
       VisItCheckForNewVisItCommand(); */

    for (i=0; i<p_nx; i++)
    {
        int ii = (i + (p_nx-1)*par_rank);
        p_xcoords[i] = ii * 2.0 + (ii*ii*0.1 * (double)(cycle));
    }
    /* If the cycle times are long you may want
       to check for commands from the Visit program
       periodically.
       VisItCheckForNewVisItCommand();  */

    for (i=0; i<p_nx; i++)
    {
        p_zvalues[i] = p_zvalues[i] + sqrt(i);
    }

#ifdef PARALLEL
    MPI_Barrier(MPI_COMM_WORLD);
    printf(" and both processors synchronized.\n");
#endif
    cycle++;
    VisItTimeStepChanged();
}

/*****************************************************************************
* Function: RunSimulation
*
* Purpose:
*   Run simulation until signaled to stop
*
* Arguments:
*
* Programmer: Shelly Prevost
* Creation:   Tue Sep 12 10:56:07 PDT 2006
*
* Modifications:
*
*****************************************************************************/
void
RunSimulation()
{
    runflag = 1;
}

/*****************************************************************************
* Function: StopSimulation
*
* Purpose:
*  Stop the simulation
*
* Arguments:
*
* Programmer: Shelly Prevost
* Creation:   Tue Sep 12 10:56:07 PDT 2006
*
* Modifications:
*
*****************************************************************************/
void
StopSimulation()
{
    runflag = 0;
    VisItTimeStepChanged();
}

/*****************************************************************************
* Function: FakeConsoleCommand
*
* Purpose:
*   Take input from the keyboard
*
* Arguments:
*  str:  send the string to all the engines
*
* Programmer: Shelly Prevost
* Creation:   Tue Sep 12 10:56:07 PDT 2006
*
* Modifications:
*
*****************************************************************************/
void
FakeConsoleCommand(char *str)
{
#ifdef PARALLEL
    char buff[10000];
    sprintf(buff, str);
    MPI_Bcast(buff, 10000, MPI_CHAR, 0, MPI_COMM_WORLD);
#endif
}

/*****************************************************************************
* Function: ProcessCommand
*
* Purpose:
*   Parse the command and execute the action
*
* Arguments:
*  cmd:  string sent from the VisIt simulation window UI
*
* Programmer: Shelly Prevost
* Creation:  Tue Sep 12 10:56:07 PDT 2006
*
* Modifications:
*
*****************************************************************************/
void
ProcessCommand(char *cmd)
{
    char sig[64];
    char commandName[256];
    char *action = NULL;

#ifdef PARALLEL
    char buff[10000];
    if (par_rank == 0)
        strcpy(buff, cmd);
    MPI_Bcast(buff, 10000, MPI_CHAR, 0, MPI_COMM_WORLD);
    cmd = buff;
#endif

    /* first strip out the command name from the rest of
       of the callback string  */
    action = VisItParseCommand(cmd, sig, commandName);

    if (!strcmp(commandName, "quit"))
    {
        quitflag = 1;
    }
    else if (!strcmp(commandName, "step"))
    {
        RunSingleCycle();
        runflag = 0;
    }
    else if (!strcmp(commandName, "run"))
    {
        RunSimulation();
    }
    else if (!strcmp(commandName, "halt"))
    {
        printf("execution paused....\n");
        StopSimulation();
    }
    else if (!strcmp(commandName, "restart"))
    {
        printf("not implemented yet....\n");
        StopSimulation();
    }
    else if (!strcmp(commandName, "sync"))
    {
        printf("not implemented yet....\n");
        StopSimulation();
    }
    else if (!strcmp(commandName, "visit_disconnect"))
    {
        VisItDisconnect();
    }
    else if (!strcmp(commandName, "visit_connect"))
    {
        VisItAttemptToCompleteConnection();
    }
    else if (!strcmp(commandName, "visit_process"))
    {
        VisItProcessEngineCommand();
    }
    else if (!strcmp(cmd, ""))
    {
        /* Do nothing on blank input. */
    }
    else
    {
        VisItProcessCustomCommand(cmd );
    }
}

/*****************************************************************************
* Function: ProcessConsoleCommand
*
* Purpose:
*   Take input from the keyboard and execute the command.
*
* Arguments:
*
* Programmer: Shelly Prevost
* Creation:   Tue Sep 12 10:56:07 PDT 2006
*
* Modifications:
*
*****************************************************************************/
void
ProcessConsoleCommand()
{
    /* Read A Command */
    char buff[10000];

    strcpy( buff,"console;");
    if (par_rank == 0)
    {
        int iseof = (fgets(&buff[8], 10000, stdin) == NULL);
        if (iseof)
        {
            sprintf(buff, "quit");
            printf("quit\n");
        }

        if (strlen(buff)>0 && buff[strlen(buff)-1] == '\n')
            buff[strlen(buff)-1] = '\0';
    }

    ProcessCommand(buff);
}

/*****************************************************************************
* Function: BroadcastSlaveCommand
*
* Purpose:
*   Send command out to all engines
*
* Arguments:
*   command: integer representing the command.
*
* Programmer: Shelly Prevost
* Creation:   Tue Sep 12 10:56:07 PDT 2006
*
* Modifications:
*
*****************************************************************************/
#define VISIT_COMMAND_PROCESS 0
#define VISIT_COMMAND_SUCCESS 1
#define VISIT_COMMAND_FAILURE 2

static void
BroadcastSlaveCommand(int *command)
{
#ifdef PARALLEL
    MPI_Bcast(command, 1, MPI_INT, 0, MPI_COMM_WORLD);
#endif
}

/*****************************************************************************
* Function: SlaveProcessCallback
*
* Purpose:
*   Catches a visit command and send it out to the rest of the engines.
*
* Arguments:
*
* Programmer: Shelly Prevost
* Creation:   Tue Sep 12 10:56:07 PDT 2006
*
* Modifications:
*
*****************************************************************************/
void
SlaveProcessCallback()
{
    int command = VISIT_COMMAND_PROCESS;
    BroadcastSlaveCommand(&command);
}

/*****************************************************************************
* Function: ControlCommandCallback
*
* Purpose:
*   This function is registered as the callback for communication with VisIt.
*
* Arguments:
*   cmd: The comnand string sent from visit.
*   int_data: not used at this time.
*   floatZ_data: not used at this time.
*   string_data: not used at this time.
*
* Programmer: Shelly Prevost
* Creation:   Tue Sep 12 10:56:07 PDT 2006
*
* Modifications:
*
*****************************************************************************/
void
ControlCommandCallback(const char *cmd, int int_data,
                       float float_data, const char *string_data)
{
    /* Ignore int/float/string_data */
    CMD_String cmd2;
    strcpy ((char *) cmd2,cmd);
    ProcessCommand((char *)cmd2);
}

/*****************************************************************************
* Function: ProcessVisItCommand
*
* Purpose:
*   If rank zero process this command and send it on to the other processes.
*
* Arguments:
*
* Programmer: Shelly Prevost
* Creation:   Tue Sep 12 10:56:07 PDT 2006
*
* Modifications:
*
*****************************************************************************/
int
ProcessVisItCommand(void)
{
    int command;
    if (par_rank==0)
    {
        int success = VisItProcessEngineCommand();

        if (success)
        {
            command = VISIT_COMMAND_SUCCESS;
            BroadcastSlaveCommand(&command);
            return 1;
        }
        else
        {
         command = VISIT_COMMAND_FAILURE;
         BroadcastSlaveCommand(&command);
         return 0;
        }
    }
    else
    {
        /* Note: only through the SlaveProcessCallback callback
         * above can the rank 0 process send a VISIT_COMMAND_PROCESS
         * instruction to the non-rank 0 processes. */
        while (1)
        {
            int command;
            BroadcastSlaveCommand(&command);
            switch (command)
            {
              case VISIT_COMMAND_PROCESS:
                VisItProcessEngineCommand();
                break;

              case VISIT_COMMAND_SUCCESS:
                return 1;

              case VISIT_COMMAND_FAILURE:
                return 0;
            }
        }
    }
}

/*****************************************************************************
* Function: VisItCheckForNewVisItCommand
*
* Purpose:
*   Look for a VisIt command. If you find one process all of them while you
*   you are stopped.
*
* Arguments:
*
* Programmer: Shelly Prevost
* Creation:   Tue Sep 12 10:56:07 PDT 2006
*
* Modifications:
*
*****************************************************************************/
int
VisItCheckForNewVisItCommand()
{
    int visitState;
    if (par_rank == 0)
    {
        do
        {
            int blocking = runflag ? FALSE : TRUE;
            visitState = VisItDetectInput(blocking, fileno(stdin));
            if ( visitState == 2 ) ProcessVisItCommand();
        }
        while ( visitState == 2 );
    }

    return visitState;
}

/*****************************************************************************
* Function: MainLoop
*
* Purpose:
*   This is the control loop one would expect to find in a simulation.  It
*   processes Commands and then computes the next cycle.
*
* Arguments:
*
* Programmer: Shelly Prevost
* Creation:   Tue Sep 12 10:56:07 PDT 2006
*
* Modifications:
*
*****************************************************************************/
void
MainLoop()
{
    if (par_rank == 0)
    {
        fprintf(stderr, "command> ");
        fflush(stderr);
    }

    while (!quitflag)
    {
        int visitstate = VisItCheckForNewVisItCommand( );

#ifdef PARALLEL
        MPI_Bcast(&visitstate, 1, MPI_INT, 0, MPI_COMM_WORLD);
#endif
        switch (visitstate)
        {
          case -5:
          case -4:
          case -3:
          case -2:
          case -1:
            /* A result less than zero is an unfixable error  */
            fprintf(stderr, "\nUnrecoverable error... exiting.\n");
            quitflag = 1;
            break;

          case 0:
            /* Timed out -- means we were running */
            RunSingleCycle();
            break;

          case 1:
            /* VisIt is connecting  */
            runflag = 0;
            if (!VisItAttemptToCompleteConnection())
            {
                if (par_rank == 0)
                {
                    char *err = VisItGetLastError();
                    if (strlen(err) > 0)
                    {
                        fprintf(stderr, "%s\n", err);
                    }
                    else
                    {
                        fprintf(stderr,
                                "VisIt failed to connect successfully\n");
                    }
                }
            }
            else
            {
                if (par_rank == 0)
                {
                    fprintf(stderr, "Connected successfully!\n");
                }
                VisItSetSlaveProcessCallback(SlaveProcessCallback);
                VisItSetCommandCallback(ControlCommandCallback);
            }
            if (par_rank == 0)
            {
                fprintf(stderr, "command> ");
                fflush(stderr);
            }
            break;

          case 2:
            /* VisIt wants to tell the engine something  */
            if (!ProcessVisItCommand())
            {
                /*Disconnect on an error or closed connection   */
                VisItDisconnect();
            }
            break;

          case 3:
            /* Someone was typing something -- fall through
               and read from the console.  */
            ProcessConsoleCommand();
            if (!quitflag && !runflag)
            {
                if (par_rank == 0)
                {
                    fprintf(stderr, "command> ");
                    fflush(stderr);
                }

            }
            break;
        }
    }
}

/*****************************************************************************
* Function: main
*
* Purpose:
*   Connection to VisIt and control callbacks are set here.  Also the socket
*   and datafile are written to the users .visit/simulation directory.
*
* Arguments:
*
* Programmer: Shelly Prevost
* Creation:   Tue Sep 12 10:56:07 PDT 2006
*
* Modifications:
*    Shelly Prevost,Thu Jul 26 16:34:40 PDT 2007
*    Added a absolute filename argument to VisItInitializeSocketAndDumpSimFile.
*
*****************************************************************************/
int
main(int argc, char *argv[])
{
    if (getenv("LD_LIBRARY_PATH")) printf("ld_library_path=%s\n", getenv("LD_LIBRARY_PATH")); else printf("ld_library_path=(null)\n");
    /* VisItAddLibraryPaths(argc, argv); */
    VisItSetupEnvironment();

#ifdef PARALLEL
    MPI_Init(&argc, &argv);
    MPI_Comm_rank (MPI_COMM_WORLD, &par_rank);
    MPI_Comm_size (MPI_COMM_WORLD, &par_size);
    printf("PARALLEL started: num procs = %d\n", par_size);
    if (par_size == 1)
    {
        printf("Probably not using mpirun; try again!!!!!!\n");
        exit(0);
    }

    VisItSetBroadcastIntFunction(visit_broadcast_int_callback);
    VisItSetBroadcastStringFunction(visit_broadcast_string_callback);
    VisItSetParallel(par_size > 1);
    VisItSetParallelRank(par_rank);
#endif

/* make a connection between the UI component, the signal and the function to call
   when the signal from that component is recieved.   */

    VisItAddConnection("Shelly_Button_2", "clicked()", testSlot);
    VisItAddConnection("Shelly_Button_3", "clicked()", testSlot2);
    VisItAddConnection("Top_Button_1", "clicked()", testSlot2);
    VisItAddConnection("Bottom_Button_2", "clicked()", testSlot);
    VisItAddConnection("RadioButton1", "clicked()", testSlot2);
    VisItAddConnection("RadioButton2", "clicked()", testSlot2);
    VisItAddConnection("RadioButton3", "clicked()", testSlot2);
    /* monitor value changed if you care about a change
       when some other radio button is pressed.   */
    VisItAddConnection("RadioButton1", "stateChanged()", testSlot2);
    VisItAddConnection("RadioButton2", "stateChanged()", testSlot2);
    VisItAddConnection("RadioButton3", "stateChanged()", testSlot2);

    VisItAddConnection("ShellyLineEdit1","textChanged()", valueChanged);
    VisItAddConnection("ShellyTable_1","currentChanged()", currentChanged);
    VisItAddConnection("ShellySlider_1","valueChanged()", valueChanged);
    VisItAddConnection("ShellyDial_1","valueChanged()", valueChanged);
    VisItAddConnection("apply", "clicked()", apply);

    VisItAddConnection("timeEdit1" ,"valueChanged()", valueChanged);
    VisItAddConnection("dateEdit1" ,"valueChanged()", valueChanged);
    VisItAddConnection("CheckBox1", "clicked()" , testSlot2);

    VisItAddConnection("StripChart","ALERT" , alert);
    VisItAddConnection( "Enable_Strip_Chart", "clicked()", enableStripChartCallback);
    VisItAddConnection( "STRIP_MIN_WIDGET_NAME", "returnedPressed()", testSlot);


    if (par_rank == 0)
    {
        VisItInitializeSocketAndDumpSimFile("proto",
                                            "Prototype Simulation",
                                            "/no/useful/path",
                                            NULL,
                                            "SimGUI_1.ui",
                                            "/g/g0/shelly/.visit/simulations/defaultTester.sim1");
        printf("\n          >>> STARTING SIMULATION PROTOTYPE <<<\n\n\n");

        printf("Known Commands:\n"
               "     quit  :        exit code\n"
               "     step  :        run for one cycle\n"
               "     run   :        run continuously\n"
               "     halt  :        stop running\n");
    }

    InitializeVariables();
    MainLoop();

#ifdef PARALLEL
    MPI_Finalize();
#endif

    return 0;
}
