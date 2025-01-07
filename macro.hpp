#ifndef ___FCF_MATH__MACRO_HPP___
#define ___FCF_MATH__MACRO_HPP___

#ifdef FCF_IMPLEMENTATION
  #ifndef FCF_MATH_IMPLEMENTATION
    #define FCF_MATH_IMPLEMENTATION
  #endif
#endif

#ifdef FCF_EXPORT
  #ifndef FCF_MATH_EXPORT
    #define FCF_MATH_EXPORT
  #endif
#endif

#ifdef FCF_IMPORT
  #ifndef FCF_MATH_IMPORT
    #define FCF_MATH_IMPORT
  #endif
#endif

#ifdef FCF_EXTERNAL_DEPENDENCIES
  #ifndef FCF_MATH_EXTERNAL_DEPENDENCIES
    #define FCF_MATH_EXTERNAL_DEPENDENCIES
  #endif
#endif

#ifndef FCF_MATH_DELC_EXTERN
  #ifdef FCF_MATH_IMPLEMENTATION
    #define FCF_MATH_DELC_EXTERN
  #else
    #define FCF_MATH_DELC_EXTERN extern
  #endif
#endif

#ifndef FCF_MATH_DECL_EXPORT
  #ifdef WIN32
    #if defined(FCF_MATH_EXPORT)
      #define FCF_MATH_DECL_EXPORT __declspec(dllexport)
    #elif defined(FCF_MATH_IMPORT)
      #define FCF_MATH_DECL_EXPORT __declspec(dllimport)
    #else
      #define FCF_MATH_DECL_EXPORT
    #endif
  #else
      #define FCF_MATH_DECL_EXPORT
  #endif
#endif

#ifndef FCF_MATH_GET_FUNCTION_INDEX
  #define FCF_MATH_GET_FUNCTION_INDEX(a_name, a_signature) \
    ::fcf::Math::FunctionRegistrator::getIndex<a_signature>(a_name)
#endif

#ifndef FCF_MATH_GET_FUNCTION
  #define FCF_MATH_GET_FUNCTION(a_index) \
    ::fcf::Math::Details::g_functions[a_index].function
#endif

#ifndef FCF_MATH_REGISTRY_FUNCTION
  #define FCF_MATH_REGISTRY_FUNCTION__VARNAME2(a_varName, a_funcName, a_line) a_varName##_##a_funcName##_##a_line
  #define FCF_MATH_REGISTRY_FUNCTION__VARNAME(a_varName, a_funcName, a_line) FCF_MATH_REGISTRY_FUNCTION__VARNAME2(a_varName, a_funcName, a_line)
  #define FCF_MATH_REGISTRY_FUNCTION(a_name, a_source, a_signature) \
    FunctionRegistrator \
      FCF_MATH_REGISTRY_FUNCTION__VARNAME(functionRegistrator, a_name, __LINE__) \
        ( \
          #a_name, \
          static_cast<a_signature>(a_source)\
        );
#endif // #ifndef FCF_MATH_REGISTRY_FUNCTION

#ifndef FCF_MATH_DECLARE_FUNCTION
  #define FCF_MATH_DECLARE_FUNCTION__VARNAME2(a_varName, a_funcName, a_line) a_varName##_##a_funcName##_##a_line
  #define FCF_MATH_DECLARE_FUNCTION__VARNAME(a_varName, a_funcName, a_line) FCF_MATH_DECLARE_FUNCTION__VARNAME2(a_varName, a_funcName, a_line)
  #define FCF_MATH_DECLARE_FUNCTION(a_name, a_sourceName, a_signature, a_sourceCode) \
    a_sourceCode; \
    ::fcf::Math::FunctionRegistrator \
      FCF_MATH_DECLARE_FUNCTION__VARNAME(functionRegistrator, a_name, __LINE__) \
        ( \
          #a_name, \
          static_cast<a_signature>(a_sourceName),\
          #a_sourceCode\
        );
#endif // #ifndef FCF_MATH_DECLARE_FUNCTION

#endif // #ifndef ___FCF_MATH__MACRO_HPP___
