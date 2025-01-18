find_package(OpenCL REQUIRED)
include_directories(OpenCL::OpenCL)
add_executable("math-test" impl.cpp
                           main.cpp
                           functions/getter.cpp
                           functions/random.cpp
                           functions/fill.cpp
                           containers/layer.cpp
                           base/typeInfo.cpp
                           base/declareFunction.cpp
                           base/declareFunctionImpl.cpp
                           )
target_link_libraries("math-test" PRIVATE OpenCL::OpenCL)

