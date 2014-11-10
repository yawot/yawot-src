#ifndef YAWOT_SHARED_OBJECT_H
#define YAWOT_SHARED_OBJECT_H

// Handle the exporting of symbols from a dynamic shared object
// across different oses.

#if defined _WIN32 || defined __CYGWIN__
  #define YAWOT_DSO_IMPORT __declspec(dllimport)
  #define YAWOT_DSO_EXPORT __declspec(dllexport)
#else
  #if __GNUC__ >= 4
    #define YAWOT_DSO_IMPORT __attribute__ ((visibility ("default")))
    #define YAWOT_DSO_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define YAWOT_DSO_IMPORT
    #define YAWOT_DSO_EXPORT
  #endif
#endif

// Now we use the generic helper definitions above to define YAWOT_API.
// YAWOT_API is used for the public API symbols. It either DSO imports or DSO exports (or does nothing for static build)

#ifdef YAWOT_SHARED_OBJECT // defined if YAWOT is compiled as a shared object
  #ifdef YAWOT_EXPORTS // defined if we are building the YAWOT DSO (instead of using it)
    #define YAWOT_API YAWOT_DSO_EXPORT
  #else
    #define YAWOT_API YAWOT_DSO_IMPORT
  #endif // YAWOT_EXPORTS
#else // YAWOT_SHARED_OBJECT is not defined: this means YAWOT is a static lib.
  #define YAWOT_API
#endif // YAWOT_SHARED_OBJECT

#endif
