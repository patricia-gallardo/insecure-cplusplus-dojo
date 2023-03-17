cmake_minimum_required(VERSION 3.22)

include(cmake/vcpkg.cmake)

project(insecure_cplusplus_dojo LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(check_bypass)
add_subdirectory(comparisons)
add_subdirectory(free_use)
#add_subdirectory(heartbleed)
add_subdirectory(signed_addition_overflow)
#add_subdirectory(string_length)
add_subdirectory(type_conversion)
add_subdirectory(yatzy)
