#ifndef ___FCF_MATH__PERCEPTRON__LAYER_HPP___
#define ___FCF_MATH__PERCEPTRON__LAYER_HPP___

#include <vector>
#include "LayerOptions.hpp"
#include "../BasicIterator.hpp"
#include "../BaseIterator.hpp"

namespace fcf {
  namespace Math {
    namespace Perceptron {

      template <typename Ty>
      class Layer {
        public:
         typedef BasicIterator< BaseIterator< Layer<Ty> > > iterator;
          Layer(const LayerOptions& a_layerOptions)
            : _data(a_layerOptions.size, 0){
          }
          size_t size() const {
            return _data.size();
          }
          Ty& operator[](size_t a_index){
            return _data[a_index];
          }
          const Ty& operator[](size_t a_index) const{
            return _data[a_index];
          }
          iterator begin(){
            return iterator(*this, 0);
          }
          iterator end(){
            return iterator(*this, _data.size());
          }
          const LayerOptions& getOptions() const {
            return _options;
          }
        private:
          LayerOptions    _options;
          std::vector<Ty> _data;
      };

    } // Perceptron namespace
  } // Math namespace
} // fcf namespace


namespace fcf {
  namespace Math {

    template <typename TContainer>
    struct ContainerInfo;

    template <typename Ty>
    struct ContainerInfo< Perceptron::Layer<Ty> > {
      typedef Perceptron::Layer<Ty> owner_type;
      typedef Ty                    data_type;
      typedef Ty                    value_type;
      enum { flat = true };
      enum { source = true };
      data_type* pointer(owner_type& a_container){
        return &a_container[0];
      }
      size_t step(const owner_type& a_container){
        return 1;
      }
      size_t totalSize(const owner_type& a_container){
        return a_container.size();
      }
    };

  } // Math namespace
} // fcf namespace

#endif // #ifndef ___FCF_MATH__PERCEPTRON__LAYER_HPP___
