cmake_minimum_required(VERSION 3.30)
project(raytracer)

set(CMAKE_CXX_STANDARD 20)

Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.8.0
)
FetchContent_MakeAvailable(Catch2)

file(GLOB_RECURSE sources src/*.cpp)

add_executable(raytracer ${sources})

enable_testing()

add_subdirectory(test)

target_include_directories(raytracer PRIVATE ${CMAKE_SOURCE_DIR}/src)