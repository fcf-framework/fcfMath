#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "../macro.hpp"

#include "../../../libraries/fcfBasis/functions.hpp"

namespace FillTest {

  struct PreSetStruct {
    int              fillvalue;
    std::vector<int> value;
    int* begin() {
      return &value[0];
    }

    int* end() {
      return &value[0] + value.size();
    }
  };


}

namespace std {
  int* begin(FillTest::PreSetStruct& a_value) {
    return &a_value.value[0];
  }

}

template <>
struct fcf::Type< FillTest::PreSetStruct > : public fcf::BaseContainerType< FillTest::PreSetStruct > {

  typedef FillTest::PreSetStruct owner_type;

  typedef int data_type;

  typedef int value_type;

  enum { container = true };

};

template <>
struct fcf::Type< FillTest::PreSetStruct, fcf::ValueSpecificator> {

  enum { enable = true };

  int value(FillTest::PreSetStruct& a_container){
    return a_container.fillvalue;
  }
};


void fillTest(){
  std::cout << "Start fillTest..." << std::endl;

  {
    std::vector<FillTest::PreSetStruct> pssv(2);
    pssv[0].fillvalue = 1;
    pssv[0].value.resize(10, 0);
    pssv[1].fillvalue = 2;
    pssv[1].value.resize(10, 0);
    fcf::fill(pssv);
    for(int v : pssv[0].value){
      FCF_MATH_TEST(v == 1);
    }
    for(int v : pssv[1].value){
      FCF_MATH_TEST(v == 2);
    }
  }
  {
    FillTest::PreSetStruct pss;
    pss.fillvalue = 7;
    pss.value.resize(10);
    fcf::fill(pss);
    for(int v : pss){
      FCF_MATH_TEST(v == 7);
    }
    for(int v : pss.value){
      FCF_MATH_TEST(v == 7);
    }
  }
  {
    int value = 0;
    fcf::fill(value, 7);
    FCF_MATH_TEST(value == 7);
  }
  {
    int value[10];
    fcf::fill(value, 0);
    for(int v : value){
      FCF_MATH_TEST(v == 0);
    }
    fcf::fill(value, 7);
    for(int v : value){
      FCF_MATH_TEST(v == 7);
    }
  }
  {
    std::vector<int> container(10, 0);
    fcf::fill(container.begin(), container.end(), 7);
    for(int v : container){
      FCF_MATH_TEST(v == 7);
    }
  }
  {
    std::vector< std::vector<int> > container(10);
    for(std::vector<int>& vec : container){
      vec.resize(10);
    }
    fcf::fill(container.begin(), container.end(), 7);
    for(std::vector<int>& vec : container){
      for(int& item : vec){
        FCF_MATH_TEST(item == 7);
      }
    }
  }
  {
    std::set<int> set;
    double data[1000];
    fcf::fill(data, 11);
    for(auto value : data){
      FCF_MATH_TEST(value == 11);
    }
  }
  {
    std::set<int> set;
    std::vector<double> data(1000);
    double* begin = &data[0];
    double* end = &data[0] + data.size();
    fcf::fill(begin, end, 11);
    for(auto value : data ){
      FCF_MATH_TEST(value == 11);
    }
  }
  {
    std::set<int> set;
    std::vector<double> data(1000);
    fcf::fill(data.begin(), data.end(), 11);
    for(auto value : data){
      FCF_MATH_TEST(value == 11);
    }
  }
  {
    std::set<int> set;
    std::vector<double> data(1000);
    fcf::fill(data, 11);
    for(auto value : data ){
      FCF_MATH_TEST(value == 11);
    }
  }
  {
    std::set<int> set;
    std::list<double> data(1000);
    fcf::fill(data, 11);
    for(auto value : data ){
      FCF_MATH_TEST(value == 11);
      set.insert((int)value);
    }
  }
}
