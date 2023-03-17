find_package(Catch2 CONFIG REQUIRED)

file(GLOB sources CONFIGURE_DEPENDS "*.cpp")
add_executable(heartbleed ${sources} heartbleed.c cmake/tests.cpp)
target_link_libraries(heartbleed PRIVATE Catch2::Catch2)

include(Catch)
catch_discover_tests(heartbleed)
