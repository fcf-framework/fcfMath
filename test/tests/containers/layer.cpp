#include <iostream>
#include "../macro.hpp"
#include "../../../functions.hpp"
#include "../../../Perceptron/Layer.hpp"
#include "../../../Perceptron/Layers.hpp"

void layerTest(){
  std::cout << "Start layerTest..." << std::endl;

  {
    fcf::Math::Perceptron::Layer<float> layer(fcf::Math::Perceptron::LayerOptions{"sig", 3, 1, -0.5, 0.5});
    fcf::Math::fill(layer, 7);
    size_t s = 0;
    for(float& value : layer) {
      FCF_MATH_TEST(value == 7);
      ++s;
    }
    FCF_MATH_TEST(s == 3);
  }
  {
    fcf::Math::Perceptron::LayerOptions lo[] = {
      fcf::Math::Perceptron::LayerOptions{"sig", 1, 1},
      fcf::Math::Perceptron::LayerOptions{"sig", 2, 1},
      fcf::Math::Perceptron::LayerOptions{"sig", 3, 1}
    };
    fcf::Math::Perceptron::Layers<float> layers(lo);
    fcf::Math::fill(layers, 7);
    size_t counter = 0;
    for(fcf::Math::Perceptron::Layer<float>& layer : layers){
      for(size_t i = 0; i < layer.size(); ++i){
        FCF_MATH_TEST(layer[i] == 7);
      }
      ++counter;
      FCF_MATH_TEST(counter == layer.size());
    }
    FCF_MATH_TEST(counter == 3);
  }


}
