add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(tests)

target_include_directories(PagmModelLib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pagm/model)
target_include_directories(PagmMathLib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pagm/math)