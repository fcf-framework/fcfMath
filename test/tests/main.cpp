#include <iostream>

#include <map>
#include <cmath>


#include "../../Perceptron/LayerOptions.hpp"
#include "../../Perceptron/LayerWeights.hpp"
#include "../../Perceptron/Weights.hpp"
#include "../../Perceptron/Layer.hpp"

#include "../../include.hpp"

void typeInfoTest();
void randomTest();
void fillTest();
void layerTest();
void declareFunctionsTest();
void getterTest();


int main(int a_argc, char* a_argv[]) {
  typeInfoTest();
  randomTest();
  fillTest();
  layerTest();
  declareFunctionsTest();
  getterTest();
  return 0;
}

