#ifndef ___FCF_MATH__FUNCTION_SIGNATURE_HPP___
#define ___FCF_MATH__FUNCTION_SIGNATURE_HPP___
#include <cstring>
#include <vector>
#include "../TypeIndex.hpp"

namespace fcf {
  namespace Math {

    namespace Details {

      template <size_t Index, size_t IndexEnd, typename... TPack>
      struct TypeInitializer {
        void operator()(unsigned int* a_codes){
        }
      };

      template <size_t Index, size_t IndexEnd, typename Ty, typename... TPack>
      struct TypeInitializer<Index, IndexEnd, Ty, TPack...> {
        void operator()(unsigned int* a_codes){
          a_codes[Index] = TypeIndex<Ty>::value;
          TypeInitializer<Index+1, IndexEnd, TPack...>()(a_codes);
        }
      };

      template <size_t IndexEnd, typename Ty>
      struct TypeInitializer<IndexEnd-1, IndexEnd, Ty> {
        void operator()(unsigned int* a_codes){
          a_codes[IndexEnd-1] = TypeIndex<Ty>::value;
        }
      };

      struct BaseFunctionSignature{
        BaseFunctionSignature(size_t a_asize)
          : argCodes(a_asize){
        }

        bool operator<(const BaseFunctionSignature& a_value) const{
          if (retCode != a_value.retCode) {
            return retCode < a_value.retCode;
          }
          if (argCodes.size() != a_value.argCodes.size()){
            return argCodes.size() < a_value.argCodes.size();
          }
          return memcmp(&argCodes[0], &a_value.argCodes[0], argCodes.size()) < 0;
        }

        bool operator==(const BaseFunctionSignature& a_value) const{
          if (retCode != a_value.retCode) {
            return false;
          }
          if (argCodes.size() != a_value.argCodes.size()){
            return false;
          }
          return memcmp(&argCodes[0], &a_value.argCodes[0], argCodes.size()) == 0;
        }

        unsigned int retCode;
        std::vector<unsigned int> argCodes;

      };

      template <typename TFunction>
      struct FunctionSignature;

      template <typename TResult, typename... TArgs>
      struct FunctionSignature<TResult (TArgs...)> : public BaseFunctionSignature{
        typedef TResult(*value_type)(TArgs...);
        FunctionSignature()
          : BaseFunctionSignature(sizeof...( TArgs) ) {
          retCode = TypeIndex<TResult>::value;
          TypeInitializer<0, sizeof...(TArgs), TArgs...>()(&argCodes[0]);
        }

      };
    } // Details namespace
  } // Math namespace
} // fcf namespace

#endif // #ifndef ___FCF_MATH__FUNCTION_SIGNATURE_HPP___
