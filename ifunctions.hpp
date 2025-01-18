#ifndef ___FCF_MATH__IFUNCTIONS_HPP___
#define ___FCF_MATH__IFUNCTIONS_HPP___

#include <cmath>
#include "macro.hpp"

#define FCF_MATH_INCLUDE_LIBRARY fcfBasis
#define FCF_MATH_INCLUDE_FILE    IndexableFunction.hpp
#include "include.hpp" // as #include <fcfBasis/IndexableFunction.hpp>


//
// sin function <float(float)>
// ------------------------------------------------------

FCF_MATH_DECL_EXPORT float fcf_sinf(float a_value);

#ifdef FCF_MATH_IMPLEMENTATION
  FCF_DECLARE_FUNCTION(sin, "*", fcf_sinf, float(*) (float),
    float fcf_sinf(float a_value) {
      return sinf(a_value);
    }
  );
#endif // #ifdef FCF_MATH_IMPLEMENTATION

#ifdef FCF_MATH_IMPLEMENTATION
  FCF_EXTEND_FUNCTION(sin, "engine_opencl", fcf_sinf, float(*) (float),
    float fcf_sinf(float a_value) {
      return sin(a_value);
    }
  );
#endif // #ifdef FCF_MATH_IMPLEMENTATION


//
// sin function <double(double)>
// ------------------------------------------------------

FCF_MATH_DECL_EXPORT double fcf_sin(double a_value);

#ifdef FCF_MATH_IMPLEMENTATION
  FCF_DECLARE_FUNCTION(sin, "*", fcf_sin, double(*) (double),
    double fcf_sin(double a_value) {
      return sin(a_value);
    }
  );
#endif // #ifdef FCF_MATH_IMPLEMENTATION


//
// sig function <float(float)>
// ------------------------------------------------------

FCF_MATH_DECL_EXPORT float  fcf_sigf(float a_value);

#ifdef FCF_MATH_IMPLEMENTATION
  FCF_DECLARE_FUNCTION(sig, "*", fcf_sigf, float(*) (float),
    float fcf_sigf(float a_value) {
      return (float)1.0 / (1.0 + expf(-a_value));
    }
  );
#endif // #ifdef FCF_MATH_IMPLEMENTATION

#ifdef FCF_MATH_IMPLEMENTATION
  FCF_EXTEND_FUNCTION(sig, "engine_opencl", fcf_sigf, float(*) (float),
    float fcf_sigf(float a_value) {
      return (float)1.0 / (1.0 + exp(-a_value));
    }
  );
#endif // #ifdef FCF_MATH_IMPLEMENTATION


//
// sig function <double(double)>
// ------------------------------------------------------

FCF_MATH_DECL_EXPORT double fcf_sig(double a_value);

#ifdef FCF_MATH_IMPLEMENTATION
  FCF_DECLARE_FUNCTION(sig, "*", fcf_sig, double(*) (double),
    double  fcf_sig(double a_value) {
      return (double)1.0 / (1.0 + exp(-a_value));
    }
  );
#endif // #ifdef FCF_MATH_IMPLEMENTATION

#endif // #ifndef ___FCF_MATH__IFUNCTIONS_HPP___
