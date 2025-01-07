#ifndef ___FCF_MATH__RANOM_DEVICE_HPP___
#define ___FCF_MATH__RANOM_DEVICE_HPP___
#include <ctime>
#include <chrono>
#include <random>
#include "macro.hpp"

namespace fcf {
  namespace Math {
    #ifdef FCF_MATH_IMPLEMENTATION
       FCF_MATH_DECL_EXPORT std::mt19937 g_randomDevice( (
          (std::mt19937::result_type)
          std::chrono::duration_cast<std::chrono::seconds>(
              std::chrono::system_clock::now().time_since_epoch()
              ).count() +
          (std::mt19937::result_type)
          std::chrono::duration_cast<std::chrono::microseconds>(
              std::chrono::high_resolution_clock::now().time_since_epoch()
              ).count() ));
    #else
      FCF_MATH_DELC_EXTERN FCF_MATH_DECL_EXPORT std::mt19937 g_randomDevice;
    #endif //#ifdef FCF_MATH_IMPLEMENTATION
  } // Math namespace
} // fcf namespace

#endif // #ifndef ___FCF_MATH__RANOM_DEVICE_HPP___

