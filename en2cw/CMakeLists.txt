# CMakeList.txt : CMake project for en2cw, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (EecInfer "src/EecInfer.cpp")
add_executable (EecTrain "src/EecTrain.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EecInfer PROPERTY CXX_STANDARD 20)
  set_property(TARGET EecTrain PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
