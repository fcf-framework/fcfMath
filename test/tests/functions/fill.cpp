#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "../macro.hpp"
#include "../../../functions.hpp"

namespace FillTest {
  struct Vector : public std::vector<float> {
    using std::vector<float>::vector;
    float value() const{
      return 11;
    }
  };
}


namespace fcf {
  namespace Math {
    template <>
    struct ContainerInfo< FillTest::Vector > {
      typedef float data_type;
      enum    { flat = false };
      enum    { source = true };
      data_type value(const FillTest::Vector& a_container){
        return a_container.value();
      }
    };
  }
}

void fillTest(){
  std::cout << "Start fillTest..." << std::endl;
  {
    std::set<int> set;
    FillTest::Vector data(1000);
    fcf::Math::fill(data);
    for(auto value : data){
      FCF_MATH_TEST(value == 11);
    }
  }
  {
    std::set<int> set;
    double data[1000];
    fcf::Math::fill(data, 11);
    for(auto value : data){
      FCF_MATH_TEST(value == 11);
    }
  }
  {
    std::set<int> set;
    std::vector<double> data(1000);
    double* begin = &data[0];
    double* end = &data[0] + data.size();
    fcf::Math::fill(begin, end, 11);
    for(auto value : data ){
      FCF_MATH_TEST(value == 11);
    }
  }
  {
    std::set<int> set;
    std::vector<double> data(1000);
    fcf::Math::fill(data.begin(), data.end(), 11);
    for(auto value : data){
      FCF_MATH_TEST(value == 11);
    }
  }
  {
    std::set<int> set;
    std::vector<double> data(1000);
    fcf::Math::fill(data, 11);
    for(auto value : data ){
      FCF_MATH_TEST(value == 11);
    }
  }
  {
    std::set<int> set;
    std::list<double> data(1000);
    fcf::Math::fill(data, 11);
    for(auto value : data ){
      FCF_MATH_TEST(value == 11);
      set.insert((int)value);
    }
  }

}
