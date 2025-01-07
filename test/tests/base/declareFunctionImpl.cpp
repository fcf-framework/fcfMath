#include "../macro.hpp"
#include "../../../FunctionRegistrator.hpp"

FCF_MATH_DECLARE_FUNCTION(test_sig2, test_dsig2, double(*) (double),
    double test_dsig2(double a_value){
      return (double)1.0 / (1.0 + exp(-a_value));
    })
FCF_MATH_DECLARE_FUNCTION(test_sig2, test_fsig2, float(*) (float),
    float test_fsig2(float a_value){
      return (float)1.0 / (1.0 + exp(-a_value));
    });
