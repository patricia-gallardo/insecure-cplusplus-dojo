find_package(Catch2 CONFIG REQUIRED)

file(GLOB sources CONFIGURE_DEPENDS "*.cpp")
add_executable(signed_addition_overflow ${sources} cmake/tests.cpp)
target_link_libraries(signed_addition_overflow PRIVATE Catch2::Catch2)

include(Catch)
catch_discover_tests(signed_addition_overflow)
