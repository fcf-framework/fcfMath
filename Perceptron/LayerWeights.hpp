#ifndef ___FCF_MATH__PERCEPTRON__LAYER_WEIGHTS_HPP___
#define ___FCF_MATH__PERCEPTRON__LAYER_WEIGHTS_HPP___

#include <vector>

#include "../macro.hpp"

#define FCF_MATH_INCLUDE_LIBRARY fcfBasis
#define FCF_MATH_INCLUDE_FILE    iterator.hpp
#include "../include.hpp" // as #include <fcfBasis/iterator.hpp>

#include "LayerOptions.hpp"

namespace fcf {
  namespace Math {
    namespace Perceptron {

      template <typename Ty>
      class LayerWeights {
        public:

          class BaseIterator {
            public:
              typedef Ty value_type;
              BaseIterator(LayerWeights<Ty>& a_weights)
                : index(0)
                , weights(a_weights)
              {
              }
              BaseIterator(LayerWeights<Ty>& a_weights, size_t a_index)
                : index(a_index)
                , weights(a_weights)
              {
              }
              bool operator==(const BaseIterator& a_it) const {
                return a_it.index == index;
              }
              Ty* operator->() {
                return weights[index];
              }
              BaseIterator& operator++(){
                index += weights.layerSize1();
                return *this;
              }
            private:
              size_t            index;
              LayerWeights<Ty>& weights;
          };
          typedef BasicIterator<BaseIterator> iterator;

          LayerWeights(LayerOptions a_layer1, LayerOptions a_layer2)
            : _layerSize1(a_layer1.size)
            , _layerSize2(a_layer2.size)
            , _initMin(a_layer2.initMin)
            , _initMax(a_layer2.initMax)
            , _data(a_layer1.size * a_layer2.size) {
          }

          unsigned int layerSize1() const {
            return _layerSize1;
          }

          unsigned int layerSize2() const {
            return _layerSize2;
          }

          size_t size() const {
            return _layerSize2;
          }

          size_t subArraySize() const {
            return _layerSize1;
          }

          Ty* operator[](unsigned int a_secondLayerIndex) {
            return &_data[_layerSize1 * a_secondLayerIndex];
          }

          const Ty* operator[](unsigned int a_secondLayerIndex) const{
            return &_data[_layerSize1 * a_secondLayerIndex];
          }

          iterator begin() {
            return iterator(*this);
          }

          iterator end() {
            return iterator(*this, size());
          }

          Ty initMin() const{
            return _initMin;
          }

          Ty initMax() const{
            return _initMax;
          }

        private:
          unsigned int    _layerSize1;
          unsigned int    _layerSize2;
          Ty              _initMin;
          Ty              _initMax;
          std::vector<Ty> _data;
      };

    } // Perceptron namespace
  } // Math namespace
} // fcf namespace

namespace fcf {

    template <typename Ty>
    struct Type< Math::Perceptron::LayerWeights<Ty> > : public fcf::BaseContainerType< Math::Perceptron::LayerWeights<Ty> > {

      typedef Math::Perceptron::LayerWeights<Ty> owner_type;

      typedef Ty data_type;

      typedef Ty* value_type;
    };

    template <typename Ty>
    struct Type< Math::Perceptron::LayerWeights<Ty>, MinMaxSpecificator > {
      Ty min(const Math::Perceptron::LayerWeights<Ty>& a_container){
        return a_container.initMin();
      }
      Ty max(const Math::Perceptron::LayerWeights<Ty>& a_container){
        return a_container.initMax();
      }
    };


} // fcf namespace


#endif // #ifndef ___FCF_MATH__PERCEPTRON__LAYER_WEIGHTS_HPP___
