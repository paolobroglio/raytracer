file(GLOB_RECURSE test_sources tests.cpp ../src/Tuple.cpp)

add_executable(tests ${test_sources})

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)

catch_discover_tests(tests)