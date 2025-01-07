#ifndef ___FCF_MATH__TEST__TESTS__MACRO_HPP___
#define ___FCF_MATH__TEST__TESTS__MACRO_HPP___

  #define FCF_MATH_TEST_STRINGIZE2(x) #x
  #define FCF_MATH_TEST_STRINGIZE(x) FCF_MATH_TEST_STRINGIZE2(x)
  #define FCF_MATH_TEST_LINE_STRING FCF_MATH_TEST_STRINGIZE(__LINE__)
  #define FCF_MATH_TEST(exp) \
    if (!(exp)){ \
      throw std::runtime_error(std::string() + "Test error: " + #exp + "  [FILE: " + __FILE__ + ":" + FCF_MATH_TEST_LINE_STRING + "]");\
    }

#endif // #ifndef ___FCF_MATH__TEST__TESTS__MACRO_HPP___
