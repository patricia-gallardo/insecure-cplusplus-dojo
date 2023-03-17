find_package(Catch2 CONFIG REQUIRED)

file(GLOB sources CONFIGURE_DEPENDS "*.cpp")
add_executable(comparisons ${sources})
target_link_libraries(comparisons PRIVATE Catch2::Catch2)

include(Catch)
catch_discover_tests(comparisons)
