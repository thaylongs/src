#ifndef __exodusII_cfg_h
#define __exodusII_cfg_h

#if 0
#define EXODUSII_VERSION_MAJOR @EXODUSII_VERSION_MAJOR@
#define EXODUSII_VERSION_MINOR @EXODUSII_VERSION_MINOR@
#define EXODUSII_VERSION_PATCH @EXODUSII_VERSION_PATCH@
#define EXODUSII_VERSION "@EXODUSII_VERSION_MAJOR@.@EXODUSII_VERSION_MINOR@.@EXODUSII_VERSION_PATCH@"
#endif

#if defined(_WIN32) && !defined(WIN32)
# define WIN32
#endif


#if defined(WIN32) && defined(EXODUSII_BUILD_SHARED_LIBS)
#  if defined(EXODUSII_EXPORTS)
#    define EXODUS_EXPORT __declspec( dllexport ) extern
#  else
#    define EXODUS_EXPORT __declspec( dllimport ) extern
#  endif
#else
#  define EXODUS_EXPORT extern
#endif

#endif

