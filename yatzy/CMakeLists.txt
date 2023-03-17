find_package(Catch2 CONFIG REQUIRED)

file(GLOB sources CONFIGURE_DEPENDS "*.cpp")
add_executable(yatzy ${sources} yatzy.c cmake/tests.cpp)
target_link_libraries(yatzy PRIVATE Catch2::Catch2)

include(Catch)
catch_discover_tests(yatzy)
