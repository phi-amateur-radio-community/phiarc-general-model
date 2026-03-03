add_library(PagmMathLib Matrix.cpp)

target_link_libraries(PagmMathLib PUBLIC PagmIoLib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET PagmMathLib PROPERTY CXX_STANDARD 20)
endif()