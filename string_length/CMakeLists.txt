find_package(Catch2 CONFIG REQUIRED)

file(GLOB sources CONFIGURE_DEPENDS "*.cpp")
add_executable(string_length ${sources})
target_link_libraries(string_length PRIVATE Catch2::Catch2)

include(Catch)
catch_discover_tests(string_length)
