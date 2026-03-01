add_library(PagmModelLib Forward.cpp Transformer.cpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET PagmModelLib PROPERTY CXX_STANDARD 20)
endif()