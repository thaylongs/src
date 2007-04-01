#ifndef PARALLEL_VISIT_VTK_EXPORTS_H
#define PARALLEL_VISIT_VTK_EXPORTS_H

#if defined(_WIN32)
#ifdef PARALLEL_VISIT_VTK_EXPORTS
#define PARALLEL_VISIT_VTK_API __declspec(dllexport)
#else
#define PARALLEL_VISIT_VTK_API __declspec(dllimport)
#endif
#if defined(USING_MSVC6) || defined(USING_MSVC7)
// Turn off warning about lack of DLL interface
#pragma warning(disable:4251)
// Turn off warning non-dll class is base for dll-interface class.
#pragma warning(disable:4275)
// Turn off warning about identifier truncation
#pragma warning(disable:4786)
#endif
#else
#define PARALLEL_VISIT_VTK_API
#endif

#endif
