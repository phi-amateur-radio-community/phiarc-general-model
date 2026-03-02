add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(tests)

target_include_directories(PagmModelLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/pagm)
target_include_directories(PagmMathLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/pagm)