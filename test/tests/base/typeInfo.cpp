#include <iostream>
#include <vector>
#include "../macro.hpp"
#include "../../../math.hpp"

void typeInfoTest() {
  std::cout << "Start typeInfoTest..." << std::endl;

  FCF_MATH_TEST(std::string(fcf::Type< std::vector<int> >::name()) == "std::vector<int>");

  {
    typedef std::map<int, char> type;
    FCF_MATH_TEST(std::string(fcf::Type< type >::name()) == "std::map<int,char>");
  }
  {
    typedef std::map<std::string, char> type;
    FCF_MATH_TEST(std::string(fcf::Type< type >::name()) == "std::map<std::string,char>");
  }
  FCF_MATH_TEST(std::string(fcf::Type< std::list<int> >::name()) == "std::list<int>");
  FCF_MATH_TEST(fcf::Type<int>::index() != fcf::Type<short>::index());
  FCF_MATH_TEST(fcf::Type<int>::index() != fcf::Type<unsigned int>::index());
}

