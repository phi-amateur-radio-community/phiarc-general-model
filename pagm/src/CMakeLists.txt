set(PAGM_MODELS "io/ModelConfig.cpp")
add_executable (PagmInfer PagmInfer.cpp ${PAGM_MODELS})
add_executable (PagmTrain PagmTrain.cpp ${PAGM_MODELS})

set(PAGM_SELF_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/pagm/include)
target_include_directories( PagmInfer PRIVATE ${PAGM_SELF_INCLUDE_DIR})
target_include_directories( PagmTrain PRIVATE ${PAGM_SELF_INCLUDE_DIR})

target_link_libraries( PagmInfer PRIVATE PagmMathLib PagmModelLib)
target_link_libraries( PagmTrain PRIVATE PagmMathLib PagmModelLib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET PagmInfer PROPERTY CXX_STANDARD 20)
    set_property(TARGET PagmTrain PROPERTY CXX_STANDARD 20)
endif()

add_subdirectory(math)
add_subdirectory(model)