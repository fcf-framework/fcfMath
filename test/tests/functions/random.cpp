#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "../macro.hpp"
#include "../../../functions.hpp"


namespace RandomTest {
  struct Vector : public std::vector<float> {
    using std::vector<float>::vector;
    float min() const{
      return 11;
    }
    float max() const{
      return 20;
    }
  };
}

namespace fcf {
  namespace Math {
    template <>
    struct ContainerInfo< RandomTest::Vector > {
      typedef float data_type;
      enum    { flat = false };
      enum    { source = true };
      data_type min(const RandomTest::Vector& a_container){
        return a_container.min();
      }
      data_type max(const RandomTest::Vector& a_container){
        return a_container.max();
      }
    };
  }
}


void randomTest(){
  std::cout << "Start randomTest..." << std::endl;
  {
    std::set<int> set;
    RandomTest::Vector data(1000);
    fcf::Math::random(data);
    for(auto value : data){
      if (value < 11 || value > 20){
        FCF_MATH_TEST(false);
      }
      set.insert((int)value);
    }
    FCF_MATH_TEST(set.size() == 9);
  }
  {
    std::set<int> set;
    double data[1000];
    fcf::Math::random(data, 1, 10);
    for(auto value : data){
      if (value < 1 || value > 10){
        FCF_MATH_TEST(false);
      }
      set.insert((int)value);
    }
    FCF_MATH_TEST(set.size() == 9);
  }
  {
    std::set<int> set;
    std::vector<double> data(1000);
    double* begin = &data[0];
    double* end = &data[0] + data.size();
    fcf::Math::random(begin, end, 1, 10);
    for(auto value : data ){
      if (value < 1 || value > 10){
        FCF_MATH_TEST(false);
      }
      set.insert((int)value);
    }
    FCF_MATH_TEST(set.size() == 9);
  }
  {
    std::set<int> set;
    std::vector<double> data(1000);
    fcf::Math::random(data.begin(), data.end(), 1, 10);
    for(auto value : data ){
      if (value < 1 || value > 10){
        FCF_MATH_TEST(false);
      }
      set.insert((int)value);
    }
    FCF_MATH_TEST(set.size() == 9);
  }
  {
    std::set<int> set;
    std::vector<double> data(1000);
    fcf::Math::random(data, 1, 10);
    for(auto value : data ){
      if (value < 1 || value > 10){
        FCF_MATH_TEST(false);
      }
      set.insert((int)value);
    }
    FCF_MATH_TEST(set.size() == 9);
  }
  {
    std::set<int> set;
    std::list<double> data(1000);
    fcf::Math::random(data, 1, 10);
    for(auto value : data ){
      if (value < 1 || value > 10){
        FCF_MATH_TEST(false);
      }
      set.insert((int)value);
    }
    FCF_MATH_TEST(set.size() == 9);
  }
}
