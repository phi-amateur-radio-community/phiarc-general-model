# CMakeList.txt : CMake project for en2cw, include source and define
# project specific logic here.
#

# Add source to this project's executable.
set(MODELS "src/model/Transformer.cpp" "src/model/Forward.cpp" "src/file/ModelConfig.cpp" "src/file/ModelPara.cpp")
add_executable (PagmInfer "src/PagmInfer.cpp" ${MODELS})
add_executable (PagmTrain "src/PagmTrain.cpp" ${MODELS})

target_include_directories( PagmInfer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories( PagmTrain PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PagmInfer PROPERTY CXX_STANDARD 20)
  set_property(TARGET PagmTrain PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
