#include <iostream>

#include <map>
#include <cmath>


#include "../../FunctionRegistrator.hpp"
#include "../../Perceptron/LayerOptions.hpp"
#include "../../Perceptron/LayerWeights.hpp"
#include "../../Perceptron/Weights.hpp"
#include "../../functions.hpp"
#include "../../Perceptron/Layer.hpp"

#include "../../include.hpp"

void randomTest();
void fillTest();
void layerTest();
void declareFunctionsTest();

int main(int a_argc, char* a_argv[]) {
  randomTest();
  fillTest();
  layerTest();
  declareFunctionsTest();

 /*
  fcf::Math::Perceptron::LayerOptions layers[] = {
        fcf::Math::Perceptron::LayerOptions{"sig", 3},
        fcf::Math::Perceptron::LayerOptions{"sig", 3, 1, -0.5, 0.5},
        fcf::Math::Perceptron::LayerOptions{"sig", 3, 1, -0.5, 0.5}
  };
  fcf::Math::Perceptron::Weights<float> weights(layers);
  fcf::Math::random(weights);

  for(size_t i = 0; i < weights.size(); ++i){
    for(size_t j = 0; j < weights[i].size(); ++j){
        for(size_t k = 0; k < weights[i].layerSize1(); ++k){
          std::cout << i << ":" << j<< ":" << k << ": "<< weights[i][j][k] << std::endl;
        }
    }
  }
  */

 /*
  unsigned int function_index = FCF_MATH_GET_FUNCTION_INDEX("cos", double (double));
  std::cout << function_index << std::endl;
  std::cout << ((double (*)(double))FCF_MATH_GET_FUNCTION(function_index))(3.14) << std::endl;
  */
  return 0;
}

