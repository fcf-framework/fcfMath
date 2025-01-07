#include <iostream>
#include "../macro.hpp"
#include "../../../functions.hpp"
#include "../../../FunctionRegistrator.hpp"

float test_fsig2(float);



FCF_MATH_DECLARE_FUNCTION(test_sig, test_dsig, double(*) (double),
    double test_dsig(double a_value){
      return (double)1.0 / (1.0 + exp(-a_value));
    })

FCF_MATH_DECLARE_FUNCTION(test_sig, test_fsig, float(*) (float),
    float test_fsig(float a_value){
      return (float)1.0 / (1.0 + exp(-a_value));
    });


void declareFunctionsTest(){
  std::cout << "Start declareFunctionsTest..." << std::endl;

  FCF_MATH_TEST(test_fsig(1.0) > 0.73 && test_fsig(1.0) < 0.74);
  unsigned int findex = FCF_MATH_GET_FUNCTION_INDEX("test_sig", double(double));
  double (*testFunc)(double) = (double(*)(double))FCF_MATH_GET_FUNCTION(findex);

  FCF_MATH_TEST(test_fsig(1.0) > 0.73 && test_fsig(1.0) < 0.74);
  FCF_MATH_TEST(testFunc(1.0) > 0.73 && testFunc(1.0) < 0.74);

  FCF_MATH_TEST(test_fsig2(1.0) > 0.73 && test_fsig2(1.0) < 0.74);

}
