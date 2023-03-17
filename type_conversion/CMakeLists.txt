find_package(Catch2 CONFIG REQUIRED)

file(GLOB sources CONFIGURE_DEPENDS "*.cpp")
add_executable(type_conversion ${sources} type_conversion.c cmake/tests.cpp)
target_link_libraries(type_conversion PRIVATE Catch2::Catch2)

include(Catch)
catch_discover_tests(type_conversion)
