enable_testing()

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)

add_executable(PagmTest PagmTest.cpp)
target_link_libraries(PagmTest PRIVATE GTest::gtest_main ${MODELS})
target_include_directories(PagmTest PRIVATE ${PROJECT_SOURCE_DIR}/include)

include(GoogleTest)

gtest_discover_tests(PagmTest)