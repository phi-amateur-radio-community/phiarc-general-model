enable_testing()

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)

add_executable(PagmTest PagmTest.cpp)
target_link_libraries(PagmTest PRIVATE GTest::gtest_main PagmMathLib PagmModelLib)
target_include_directories(PagmTest PRIVATE ${PROJECT_SOURCE_DIR}/pagm/include)

include(GoogleTest)

gtest_discover_tests(PagmTest)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET PagmTest PROPERTY CXX_STANDARD 20)
endif()