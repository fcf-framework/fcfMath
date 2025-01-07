#ifndef ___FCF_MATH__PERCEPTRON__WEIGHTS_HPP___
#define ___FCF_MATH__PERCEPTRON__WEIGHTS__HPP___

#include <memory>
#include <vector>
#include "LayerOptions.hpp"
#include "LayerWeights.hpp"
#include "../functions.hpp"
#include "../BasicIterator.hpp"
namespace fcf {
  namespace Math {
    namespace Perceptron {

      template <typename Ty>
      class Weights {
        public:
          typedef Weights wieghts_type;
          typedef std::shared_ptr< LayerWeights<Ty> > PLayerWeights;

          class BaseIterator {
            public:
              typedef LayerWeights<Ty> value_type;
              BaseIterator(wieghts_type& a_weights)
                : index(0)
                , wieghts(a_weights)
              {
              }
              BaseIterator(wieghts_type& a_weights, size_t a_index)
                : index(a_index)
                , wieghts(a_weights)
              {
              }
              bool operator==(const BaseIterator& a_it) const {
                return a_it.index == index;
              }
              LayerWeights<Ty>* operator->() {
                return &wieghts[index];
              }
              BaseIterator& operator++(){
                ++index;
                return *this;
              }
            private:
              size_t        index;
              wieghts_type& wieghts;
          };
          typedef BasicIterator<BaseIterator> iterator;

          template <typename TLayers>
          Weights(const TLayers& a_layers) {
            _initialize(std::begin(a_layers), std::end(a_layers));
          }

          Weights(const LayerOptions* a_layers, size_t a_layerCount) {
            _initialize(a_layers, a_layers + a_layerCount);
          }

          size_t getLayerSize(size_t a_index) const {
            return _layers.size();
          }

          const LayerOptions& getLayer(size_t a_index) const {
            return _layers[a_index];
          }

          size_t size() const {
            return _weights.size();
          }

          LayerWeights<Ty>& operator[](size_t a_weightsIndex) {
            return *_weights[a_weightsIndex].get();
          }

          const LayerWeights<Ty>& operator[](size_t a_weightsIndex) const {
            return *_weights[a_weightsIndex].get();
          }

          iterator begin() {
            return iterator(*this);
          }

          iterator end() {
            return iterator(*this, size());
          }

        private:
          template <typename TIterator>
          void _initialize(TIterator a_layerBegin, TIterator a_layerEnd) {
            TIterator lastIt = a_layerEnd;
            for(TIterator it = a_layerBegin; it != a_layerEnd; ++it) {
              if (!it->size) {
                throw std::runtime_error("Layer size cannot be empty");
              }
              _layers.push_back(*it);
              if (lastIt != a_layerEnd) {
                PLayerWeights plw(new LayerWeights<Ty>(*lastIt, *it));
                _weights.push_back(plw);
              }
              lastIt = it;
            }
            if (_weights.empty()) {
              throw std::runtime_error("The number of layers cannot be less than 2");
            }
          }

          std::vector<PLayerWeights> _weights;
          std::vector<LayerOptions>  _layers;
      };

    } // Perceptron namespace
  } // Math namespace
} // fcf namespace

namespace fcf {
  namespace Math {

    template <typename Ty>
    struct ContainerInfo< Perceptron::Weights<Ty> > {
      typedef Ty data_type;
      enum    { flat = false };
      enum    { source = false };
    };
  } // Math namespace
} // fcf namespace


#endif // #ifndef ___FCF_MATH__PERCEPTRON__WEIGHTS_HPP___
