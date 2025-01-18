#ifndef ___FCF_MATH__PERCEPTRON__LAYER_HPP___
#define ___FCF_MATH__PERCEPTRON__LAYER_HPP___

#include <vector>
#include "LayerOptions.hpp"

#define FCF_MATH_INCLUDE_LIBRARY fcfBasis
#define FCF_MATH_INCLUDE_FILE    iterator.hpp
#include "../include.hpp" // as #include <fcfBasis/iterator.hpp>

namespace fcf {
  namespace Math {
    namespace Perceptron {

      template <typename Ty>
      class Layer {
        public:
          typedef BasicIterator< BaseIndexIterator< Layer<Ty> > > iterator;

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

  template <typename Ty>
  struct Type< Math::Perceptron::Layer<Ty> > : public fcf::BaseContainerType< Math::Perceptron::Layer<Ty> > {

    typedef Math::Perceptron::Layer<Ty> owner_type;

    typedef Ty data_type;

    typedef Ty value_type;

  };
} // fcf namespace

#endif // #ifndef ___FCF_MATH__PERCEPTRON__LAYER_HPP___
