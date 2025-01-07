#ifndef ___FCF_MATH__BASE_ITERATOR_HPP___
#define ___FCF_MATH__BASE_ITERATOR_HPP___



namespace fcf {
  namespace Math {

    template <typename TContainer>
    class BaseIterator {
      public:
        typedef TContainer                                     owner_type;
        typedef typename ContainerInfo<owner_type>::value_type value_type;
        BaseIterator(owner_type& a_owner)
          : _index(0)
          , _owner(a_owner)
        {
        }
        BaseIterator(owner_type& a_owner, size_t a_index)
          : _index(a_index)
          , _owner(a_owner)
        {
        }
        bool operator==(const BaseIterator& a_it) const {
          return a_it._index == _index;
        }
        value_type* operator->() {
          return &_owner[_index];
        }
        BaseIterator& operator++(){
          _index += ContainerInfo<owner_type>().step(_owner);
          return *this;
        }
      private:
        size_t      _index;
        owner_type& _owner;
    };

  } // Math namespace
} // fcf namespace

#endif // #ifndef ___FCF_MATH__BASE_ITERATOR_HPP___
