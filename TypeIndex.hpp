#ifndef ___FCF_MATH__TYPE_INDEX_HPP___
#define ___FCF_MATH__TYPE_INDEX_HPP___

#include "type.hpp"

namespace fcf {
  namespace Math {

    template <typename Ty>
    struct TypeIndex;

    template <>
    struct TypeIndex<void> {
      enum { value = 0 };
    };

    template <>
    struct TypeIndex<fcf_int8> {
      enum { value = FCF_INT8_TYPE_INDEX };
    };

    template <>
    struct TypeIndex<fcf_uint8> {
      enum { value = FCF_UINT8_TYPE_INDEX };
    };

    template <>
    struct TypeIndex<fcf_int16> {
      enum { value = FCF_INT16_TYPE_INDEX };
    };

    template <>
    struct TypeIndex<fcf_uint16> {
      enum { value = FCF_UINT16_TYPE_INDEX };
    };

    template <>
    struct TypeIndex<fcf_int32> {
      enum { value = FCF_INT32_TYPE_INDEX };
    };

    template <>
    struct TypeIndex<fcf_uint32> {
      enum { value = FCF_UINT32_TYPE_INDEX };
    };

    template <>
    struct TypeIndex<fcf_float32> {
      enum { value = FCF_FLOAT32_TYPE_INDEX };
    };

    template <>
    struct TypeIndex<fcf_float64> {
      enum { value = FCF_FLOAT64_TYPE_INDEX };
    };

    template <>
    struct TypeIndex<fcf_float80> {
      enum { value = FCF_FLOAT80_TYPE_INDEX };
    };

  } // Math namespace
} // fcf namespace

#endif // #ifndef ___FCF_MATH__TYPE_INDEX_HPP__
