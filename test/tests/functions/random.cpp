#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "../macro.hpp"
#include "../../../libraries/fcfBasis/functions.hpp"

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


template <>
struct fcf::Type< RandomTest::Vector > : public fcf::BaseContainerType< RandomTest::Vector > {

  typedef RandomTest::Vector owner_type;

  typedef int data_type;

  typedef int value_type;

  enum { container = true };

};

template <>
struct fcf::Type< RandomTest::Vector, fcf::MinMaxSpecificator> {

  enum { enable = true };

  float min(RandomTest::Vector& a_container){
    return a_container.min();
  }

  float max(RandomTest::Vector& a_container){
    return a_container.max();
  }
};

void randomTest(){
  std::cout << "Start randomTest..." << std::endl;
  {
    std::set<int> set;
    RandomTest::Vector data(1000);
    fcf::random(data);
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
    fcf::random(data, 1, 10);
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
    fcf::random(begin, end, 1, 10);
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
    fcf::random(data.begin(), data.end(), 1, 10);
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
    fcf::random(data, 1, 10);
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
    fcf::random(data, 1, 10);
    for(auto value : data ){
      if (value < 1 || value > 10){
        FCF_MATH_TEST(false);
      }
      set.insert((int)value);
    }
    FCF_MATH_TEST(set.size() == 9);
  }
}
