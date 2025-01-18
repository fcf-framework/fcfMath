#include "macro.hpp"


#ifndef FCF_MATH_EXTERNAL_DEPENDENCIES
  #ifdef FCF_MATH_IMPLEMENTATION
    #ifndef FCF_PARALLEL_IMPLEMENTATION
      #define FCF_PARALLEL_IMPLEMENTATION
    #endif
  #endif
  #ifdef FCF_MATH_EXPORT
    #ifndef FCF_PARALLEL_EXPORT
      #define FCF_PARALLEL_EXPORT
    #endif
  #endif
#endif

#ifndef FCF_MATH_EXTERNAL_DEPENDENCIES
  #ifdef FCF_MATH_IMPLEMENTATION
    #ifndef FCF_BASIS_IMPLEMENTATION
      #define FCF_BASIS_IMPLEMENTATION
    #endif
  #endif
  #ifdef FCF_MATH_EXPORT
    #ifndef FCF_BASIS_EXPORT
      #define FCF_BASIS_EXPORT
    #endif
  #endif
#endif

#if defined(FCF_MATH_INCLUDE_LIBRARY) && defined(FCF_MATH_INCLUDE_FILE)
  #ifndef FCF_MATH_EXTERNAL_DEPENDENCIES
    #define FCF_MATH_INCLUDE_LINE FCF_MATH_STR(libraries/FCF_MATH_INCLUDE_LIBRARY/FCF_MATH_INCLUDE_FILE)
  #else
    #define FCF_MATH_INCLUDE_LINE <libraries/FCF_MATH_INCLUDE_LIBRARY/FCF_MATH_INCLUDE_FILE>
  #endif
  #include FCF_MATH_INCLUDE_LINE
  #undef FCF_MATH_INCLUDE_LIBRARY
  #undef FCF_MATH_INCLUDE_FILE
  #undef FCF_MATH_INCLUDE_LINE
#else
  #ifndef FCF_MATH_EXTERNAL_DEPENDENCIES
    #include "libraries/fcfParallel/parallel.hpp"
    #include "libraries/fcfBasis/basis.hpp"
  #else
    #include <fcfParallel/parallel.hpp>
    #include <fcfBasis/basis.hpp>
  #endif
#endif // #if defined(FCF_INCLUDE_LIBRARY) && defined(FCF_INCLUDE_FILE)




