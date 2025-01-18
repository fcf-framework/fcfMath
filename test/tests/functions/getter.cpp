#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "../macro.hpp"
#include "../../../math.hpp"


FCF_PARALLEL_UNIT(fcf_math_test__getter_001,
                  {
                    extensions: [ { name: "fcf_function" } ]
                  },
                  void FCF_PARALLEL_MAIN(const FCFParallelTask* a_task,
                                         unsigned int a_functionIndex,
                                         float a_value,
                                         FCF_PARALLEL_GLOBAL float* a_values
                                        ){
                    a_values[a_task->lowIndex] = ((float (*)(float))FCF_GET_FUNCTION(a_functionIndex))(a_value);
                  }
                )


void getterTest(){
  std::cout << "Start getterTest..." << std::endl;

  {
    fcf::Parallel::Executor executor;
    executor.enableEngines(false);
    executor.enableEngines(true, "gpu", 1);
    executor.initialize();

    fcf::Parallel::Call call;
    call.name = "fcf_math_test__getter_001";
    call.size = 1000;

    std::vector<float> values(call.size);
    unsigned int sigIndex = FCF_GET_FUNCTION_INDEX("sig", float(*)(float));

    executor(call,
             sigIndex,
             (float)7,
             fcf::Parallel::refArg(values, fcf::Parallel::ArgUpload(true), fcf::Parallel::ArgSplit(fcf::Parallel::PS_FULL))
            );

    for(float& value : values){
      float expeced = fcf_sigf(7);
      FCF_MATH_TEST(value == expeced);
    }
  }
  {
    fcf::Parallel::Executor executor;
    executor.enableEngines(false);
    executor.enableEngines(true, "cpu", 1);
    executor.initialize();

    fcf::Parallel::Call call;
    call.name = "fcf_math_test__getter_001";
    call.size = 1000;

    std::vector<float> values(call.size);
    unsigned int sigIndex = FCF_GET_FUNCTION_INDEX("sig", float(*)(float));

    executor(call,
             sigIndex,
             (float)7,
             fcf::Parallel::refArg(values, fcf::Parallel::ArgUpload(true), fcf::Parallel::ArgSplit(fcf::Parallel::PS_FULL))
            );

    for(float& value : values){
      float expeced = fcf_sigf(7);
      FCF_MATH_TEST(value == expeced);
    }
  }
  {
    fcf::Parallel::Executor executor;
    executor.initialize();

    fcf::Parallel::Call call;
    call.name = "fcf_math_test__getter_001";
    call.size = 1000;

    std::vector<float> values(call.size);
    unsigned int sigIndex = FCF_GET_FUNCTION_INDEX("sig", float(*)(float));

    executor(call,
             sigIndex,
             (float)7,
             fcf::Parallel::refArg(values, fcf::Parallel::ArgUpload(true), fcf::Parallel::ArgSplit(fcf::Parallel::PS_FULL))
            );

    for(float& value : values){
      float expeced = fcf_sigf(7);
      FCF_MATH_TEST(value == expeced);
    }
  }

}


