find_package(Catch2 CONFIG REQUIRED)

file(GLOB sources CONFIGURE_DEPENDS "*.cpp")
add_executable(free_use ${sources})
target_link_libraries(free_use PRIVATE Catch2::Catch2)

include(Catch)
catch_discover_tests(free_use)
