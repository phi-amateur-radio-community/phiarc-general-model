add_library(PagmIoLib Config.cpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET PagmIoLib PROPERTY CXX_STANDARD 20)
endif()