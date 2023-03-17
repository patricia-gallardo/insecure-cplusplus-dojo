find_package(Catch2 CONFIG REQUIRED)

file(GLOB sources CONFIGURE_DEPENDS "*.cpp")
add_executable(check_bypass ${sources} cmake/tests.cpp)
target_link_libraries(check_bypass PRIVATE Catch2::Catch2)

include(Catch)
catch_discover_tests(check_bypass)
