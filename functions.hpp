#ifndef ___FCF_MATH__FUNCTIONS_HPP___
#define ___FCF_MATH__FUNCTIONS_HPP___

#include <cmath>
#include <iostream>
#include "macro.hpp"
#include "randomDevice.hpp"


namespace fcf {
  namespace Math {
    template <typename TContainer>
    struct ContainerInfo {
      typedef typename TContainer::value_type data_type;
      enum   { flat = false };
      enum   { source = true };
    };

    template <typename TItem, size_t Size>
    struct ContainerInfo<TItem[Size]> {
      typedef TItem data_type;
      enum   { flat = true };
      enum   { source = true };
      template<typename TContainer>
      data_type* pointer(TContainer& a_container) {
        return &a_container[0];
      }
      template<typename TContainer>
      size_t totalSize(TContainer& a_container) {
        return Size;
      }
    };
  }
}


namespace fcf {
  namespace Math {
    namespace Details {

      template <typename TCaller, typename Ty>
      struct InvariantCall;


      template <typename TCaller, typename Ty, bool IsFlat, bool IsSource>
      struct InvariantCallFlat {
        template <typename TContainer, typename... TArgPack>
        inline void operator()(TContainer& a_container, TArgPack... a_argPack) {
          typedef typename ContainerInfo< TContainer >::data_type data_type;
          data_type* begin = ContainerInfo< TContainer >().pointer(a_container);
          data_type* end   = ContainerInfo< TContainer >().pointer(a_container) +
                             ContainerInfo< TContainer >().totalSize(a_container);
          TCaller()(a_container, begin, end, a_argPack...);
        }
      };

      template <typename TCaller, typename Ty>
      struct InvariantCallFlat<TCaller, Ty, false, true> {
        template <typename TContainer, typename... TArgPack>
        inline void operator()(TContainer& a_container, TArgPack... a_argPack) {
          auto begin = std::begin(a_container);
          auto end = std::end(a_container);
          TCaller()(a_container, begin, end, a_argPack...);
        }
      };

      template <typename TCaller, typename Ty>
      struct InvariantCallFlat<TCaller, Ty, false, false> {
        template <typename TContainer, typename... TArgPack>
        inline void operator()(TContainer& a_container, TArgPack... a_argPack) {
          auto end = std::end(a_container);
          for(auto it = std::begin(a_container); it != end; ++it) {
            TCaller()(*it, a_argPack...);
          }
        }
      };

      template <typename TCaller, typename Ty>
      struct InvariantCall {
        template <typename TContainer, typename... TArgPack>
        inline void operator()(TContainer& a_container, TArgPack... a_argPack) {
          InvariantCallFlat<TCaller, Ty, ContainerInfo<TContainer>::flat, ContainerInfo<TContainer>::source>()(a_container, a_argPack...);
        }
      };
    }
  }
}

namespace fcf {
  namespace Math {

    template <typename Ty>
    Ty sig(Ty a_value) {
      return (Ty)1 / ((Ty)1 + std::exp(-a_value));
    }

    template <typename Ty1, typename Ty2>
    Ty1 random(Ty1 a_min, Ty2 a_max) {
      double r = (double)g_randomDevice() / (unsigned int)0xffffffff;
      return a_min + (((Ty1)a_max - a_min) * r);
    }

    template <typename TIterator, typename TMinValue, typename TMaxValue >
    void random(TIterator a_begin, TIterator a_end, TMinValue a_min, TMaxValue a_max) {
      for(; a_begin != a_end; ++a_begin) {
        *a_begin = random(a_min, a_max);
      }
    }


    template <typename TContainer, typename TMinValue, typename TMaxValue >
    void random(TContainer& a_container, TMinValue a_min, TMaxValue a_max);

    template <typename TContainer >
    void random(TContainer& a_container);

    namespace Details {
      struct RandomCaller{
        template <typename Ty>
        inline void operator()(Ty& a_container) {
          random(a_container);
        }

        template <typename TContainer, typename TMinValue, typename TMaxValue>
        inline void operator()(TContainer& a_container, TMinValue a_min, TMaxValue a_max) {
          typedef typename ContainerInfo<TContainer>::data_type data_type;
          random(a_container, (data_type)a_min, (data_type)a_max);
        }

        template <typename TContainer, typename TIterator >
        inline void operator()(TContainer& a_container, TIterator a_begin, TIterator a_end) {
          ContainerInfo<TContainer> ci;
          random(a_begin, a_end, ci.min(a_container), ci.max(a_container));
        }

        template <typename TContainer, typename TIterator, typename TMinValue, typename TMaxValue >
        inline void operator()(TContainer& a_container, TIterator a_begin, TIterator a_end, TMinValue a_min, TMaxValue a_max) {
          typedef typename ContainerInfo<TContainer>::data_type data_type;
          random(a_begin, a_end, (data_type)a_min, (data_type)a_max);
        }
      };
    }

    template <typename TContainer, typename TMinValue, typename TMaxValue >
    void random(TContainer& a_container, TMinValue a_min, TMaxValue a_max) {
      Details::InvariantCall<Details::RandomCaller, TContainer>()(a_container, a_min, a_max);
    }

    template <typename TContainer >
    void random(TContainer& a_container) {
      Details::InvariantCall<Details::RandomCaller, TContainer>()(a_container);
    }

    template <typename TIterator, typename TValue>
    void fill(TIterator a_begin, TIterator a_end, TValue a_value) {
      for(; a_begin != a_end; ++a_begin) {
        *a_begin = a_value;
      }
    }

    template <typename TContainer, typename TValue >
    void fill(TContainer& a_container, TValue a_value);
    template <typename TContainer >
    void fill(TContainer& a_container);


    namespace Details {
      struct FillCaller{
        template <typename Ty>
        inline void operator()(Ty& a_container) {
          fcf::Math::fill(a_container);
        }

        template <typename TContainer, typename TValue>
        inline void operator()(TContainer& a_container, TValue a_value) {
          typedef typename ContainerInfo<TContainer>::data_type data_type;
          fcf::Math::fill(a_container, (data_type)a_value);
        }

        template <typename TContainer, typename TIterator >
        inline void operator()(TContainer& a_container, TIterator a_begin, TIterator a_end) {
          ContainerInfo<TContainer> ci;
          fcf::Math::fill(a_begin, a_end, ci.value(a_container));
        }

        template <typename TContainer, typename TIterator, typename TValue >
        inline void operator()(TContainer& a_container, TIterator a_begin, TIterator a_end, TValue a_value) {
          fcf::Math::fill(a_begin, a_end, a_value);
        }
      };
    }

    template <typename TContainer, typename TValue >
    void fill(TContainer& a_container, TValue a_value) {
      Details::InvariantCall<Details::FillCaller, TContainer>()(a_container, a_value);
    }

    template <typename TContainer >
    void fill(TContainer& a_container) {
      Details::InvariantCall<Details::FillCaller, TContainer>()(a_container);
    }

  }
}

#endif
