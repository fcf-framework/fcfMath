#ifndef ___FCF_MATH__PERCEPTRON__LAYER_OPTIONS_HPP___
#define ___FCF_MATH__PERCEPTRON__LAYER_OPTIONS_HPP___

namespace fcf {
  namespace Math {
    namespace Perceptron {
      struct LayerOptions {
        std::string  activation;
        unsigned int size;
        double       offset;
        double       initMin;
        double       initMax;
      };
    } // Perceptron namespace
  } // Math namespace
} // fcf namespace

#endif // #ifndef ___FCF_MATH__PERCEPTRON__LAYER_OPTIONS_HPP___
