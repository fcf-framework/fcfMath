#ifndef ___FCF_MATH__PERCEPTRON__LAYERS_HPP___
#define ___FCF_MATH__PERCEPTRON__LAYERS_HPP___

#include <memory>
#include "Layer.hpp"


namespace fcf {
  namespace Math {
    namespace Perceptron {

      template <typename Ty>
      class Layers {
        typedef std::shared_ptr< Layer<Ty> > PLayer;
        public:
          typedef BasicIterator< BaseIterator< Layers<Ty> > > iterator;

          template <typename TLayersOptions>
          Layers(const TLayersOptions& a_lo) {
            auto begin = std::begin(a_lo);
            auto end = std::end(a_lo);
            for(; begin != end; ++begin) {
              _layers.push_back(PLayer(new Layer<Ty>(*begin)));
            }
          }
          size_t size() const {
            return _layers.size();
          }
          Layer<Ty>& operator[](size_t a_index){
            return *_layers[a_index];
          }
          const Layer<Ty>& operator[](size_t a_index) const{
            return *_layers[a_index];
          }
          Layer<Ty>& front(){
            return *_layers.front();
          }
          const Layer<Ty>& front() const{
            return *_layers.front();
          }
          Layer<Ty>& back(){
            return *_layers.back();
          }
          const Layer<Ty>& back() const{
            return *_layers.back();
          }
          iterator begin(){
            return iterator(*this, 0);
          }
          iterator end(){
            return iterator(*this, _layers.size());
          }
        private:
          std::vector<PLayer> _layers;
      };

    } // Perceptron namespace
  } // Math namespace
} // fcf namespace

namespace fcf {
  namespace Math {

    template <typename Ty>
    struct ContainerInfo< Perceptron::Layers<Ty> > {
      typedef Perceptron::Layers<Ty> owner_type;
      typedef Ty                     data_type;
      typedef Perceptron::Layer<Ty>  value_type;
      enum { flat = false };
      enum { source = false };
      size_t step(const owner_type& a_container){
        return 1;
      }
    };

  } // Math namespace
} // fcf namespace

#endif // #ifndef ___FCF_MATH__PERCEPTRON__LAYERS_HPP___
