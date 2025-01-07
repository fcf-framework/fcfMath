#ifndef ___FCF_MATH__BASIC_ITERATOR_HPP___
#define ___FCF_MATH__BASIC_ITERATOR_HPP___

namespace fcf {
  namespace Math {
    template <typename TBaseIterator>
    class BasicIterator : public TBaseIterator {
      public:
        using TBaseIterator::TBaseIterator;
        typename TBaseIterator::value_type& operator*(){
          return *TBaseIterator::operator->();
        }
        bool operator!=(const BasicIterator& a_it) const{
          return !TBaseIterator::operator==(a_it);
        }
        BasicIterator& operator++(){
          return (BasicIterator&)TBaseIterator::operator++();
        }
        BasicIterator operator++(int){
          BasicIterator it(*this);
          TBaseIterator::operator++();
          return it;
        }
    };
  } // Math namespace
} // fcf namespace

#endif // #ifndef ___FCF_MATH__BASIC_ITERATOR_HPP___
