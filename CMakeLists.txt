cmake_minimum_required(VERSION 3.20)
project(beam_native_service LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
enable_testing()

add_library(beam_core
    src/MeetingManager.cpp
    src/DeviceManager.cpp
)

target_include_directories(beam_core PUBLIC include)

add_executable(beam_native_service
    src/main.cpp
)

target_link_libraries(beam_native_service PRIVATE beam_core)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(beam_tests
    tests/MeetingManagerTest.cpp
    tests/DeviceManagerTest.cpp
)

target_link_libraries(beam_tests
    PRIVATE
    beam_core
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(beam_tests)
