#ifndef ___FCF_MATH__INCLUDE_HPP___
#define ___FCF_MATH__INCLUDE_HPP___

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
  #include "libraries/fcfParallel/parallel.hpp"
#else
  #include <fcfParallel/parallel.hpp>
#endif


#endif

