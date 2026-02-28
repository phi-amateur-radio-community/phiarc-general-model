set(MODELS "model/Transformer.cpp" "model/Forward.cpp" "file/ModelConfig.cpp" "file/ModelPara.cpp")
add_executable (PagmInfer PagmInfer.cpp ${MODELS})
add_executable (PagmTrain PagmTrain.cpp ${MODELS})

target_include_directories( PagmInfer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories( PagmTrain PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET PagmInfer PROPERTY CXX_STANDARD 20)
    set_property(TARGET PagmTrain PROPERTY CXX_STANDARD 20)
endif()