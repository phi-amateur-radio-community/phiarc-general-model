add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(tests)

target_include_directories(PagmModelLib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pagm/model ${CMAKE_CURRENT_SOURCE_DIR}/include/pagm)
target_include_directories(PagmMathLib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pagm/math ${CMAKE_CURRENT_SOURCE_DIR}/include/pagm)