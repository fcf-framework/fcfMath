#ifndef ___FCF_MATH__FUNCTION_REGISTRATOR_HPP___
#define ___FCF_MATH__FUNCTION_REGISTRATOR_HPP___

#include <cmath>
#include <string>
#include <stdexcept>
#include <map>
#include <vector>
#include "macro.hpp"
#include "Details/FunctionSignature.hpp"
#include "functions.hpp"

namespace fcf {
  namespace Math {

    namespace Details {
      typedef void(*opfunction_type)();
      typedef std::map< Details::BaseFunctionSignature, std::map<std::string, unsigned int>  > opfuncindex_type;
      struct RegFunctionInfo {
        opfunction_type        function;
        std::string            code;
        BaseFunctionSignature  signature;
      };
      FCF_MATH_DELC_EXTERN FCF_MATH_DECL_EXPORT opfuncindex_type g_funcIndexes;
      FCF_MATH_DELC_EXTERN FCF_MATH_DECL_EXPORT std::vector<RegFunctionInfo> g_functions;
    } // Details namespace

    struct FunctionRegistrator {
      template <typename TFunctionResult, typename... TArgPack>
      FunctionRegistrator(const std::string& a_name, TFunctionResult (*a_function)(TArgPack...), std::string a_sourceCode = std::string()){
        Details::FunctionSignature<TFunctionResult (TArgPack...)> fs;
        Details::opfuncindex_type::iterator it = Details::g_funcIndexes.find(fs);
        if (it == Details::g_funcIndexes.end()) {
          Details::opfuncindex_type::value_type newItem(fs, Details::opfuncindex_type::value_type::second_type());
          it = Details::g_funcIndexes.insert(newItem).first;
        }
        Details::opfuncindex_type::value_type::second_type::iterator indexIt = it->second.find(a_name);
        if (indexIt == it->second.end()) {
          unsigned int index = Details::g_functions.size();
          Details::RegFunctionInfo rfi{(Details::opfunction_type)a_function, a_sourceCode, fs};
          Details::g_functions.push_back(rfi);
          it->second[a_name] = index;
        } else {
          Details::g_functions[indexIt->second].code = a_sourceCode;
          Details::g_functions[indexIt->second].function = (Details::opfunction_type)a_function;
        }
      }

      template <typename TFunction>
      static unsigned int getIndex(const std::string& a_name){
        Details::FunctionSignature<TFunction> fs;
        Details::opfuncindex_type::iterator it = Details::g_funcIndexes.find(fs);
        if (it == Details::g_funcIndexes.end()) {
          throw std::runtime_error(std::string() + "Function \"" + a_name + "\" not found");
        }
        Details::opfuncindex_type::value_type::second_type::iterator itFunc = it->second.find(a_name);
        if (itFunc == it->second.end()) {
          throw std::runtime_error(std::string() + "Function \"" + a_name + "\" not found");
        }
        return itFunc->second;
      }

    };

    #ifdef FCF_MATH_IMPLEMENTATION
      namespace Details {
        FCF_MATH_REGISTRY_FUNCTION(sin, std::sin, float(*)(float));
        FCF_MATH_REGISTRY_FUNCTION(sin, std::sin, double(*)(double));
        FCF_MATH_REGISTRY_FUNCTION(sin, std::sin, long double(*)(long double));
        FCF_MATH_REGISTRY_FUNCTION(cos, std::cos, float(*)(float));
        FCF_MATH_REGISTRY_FUNCTION(cos, std::cos, double(*)(double));
        FCF_MATH_REGISTRY_FUNCTION(cos, std::cos, long double(*)(long double));
        FCF_MATH_REGISTRY_FUNCTION(tan, std::tan, float(*)(float));
        FCF_MATH_REGISTRY_FUNCTION(tan, std::tan, double(*)(double));
        FCF_MATH_REGISTRY_FUNCTION(tan, std::tan, long double(*)(long double));
        FCF_MATH_REGISTRY_FUNCTION(sig, sig, float(*)(float));
        FCF_MATH_REGISTRY_FUNCTION(sig, sig, double(*)(double));
        FCF_MATH_REGISTRY_FUNCTION(sig, sig, long double(*)(long double));
      } // Details namespace
    #endif // #ifdef FCF_MATH_IMPLEMENTATION


  } // Math namespace
} // fcf namespace
#endif // #ifndef ___FCF_MATH__FUNCTION_REGISTRATOR_HPP___
