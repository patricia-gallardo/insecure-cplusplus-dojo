// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include "free_use.hpp"
#include <catch2/catch.hpp>

TEST_CASE("CWE-415 and CWE-416: Free In Error Path", "[Ex433]") {
  {
    char * buffer = make_buffer(4);
    REQUIRE(buffer != nullptr);
    free(buffer);
  }
#if 0
  {
    char * buffer = make_buffer(5);
    REQUIRE(buffer != nullptr);
    free(buffer);
  }
#endif
}
