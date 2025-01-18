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

#define FCF_MATH_STR_L1(a_arg1) #a_arg1
#define FCF_MATH_STR(a_arg1) FCF_MATH_STR_L1(a_arg1)

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

#ifndef FCF_GET_FUNCTION_INDEX
  #define FCF_GET_FUNCTION_INDEX(a_name, a_signature) \
    ::fcf::IndexableFunctionRegistrator::getIndex<a_signature>(a_name)
#endif

#ifndef FCF_GET_FUNCTION
  #define FCF_GET_FUNCTION(a_index) \
    ::fcf::Details::IndexableFunction::getStorage().functions[a_index].function
#endif

#endif // #ifndef ___FCF_MATH__MACRO_HPP___
