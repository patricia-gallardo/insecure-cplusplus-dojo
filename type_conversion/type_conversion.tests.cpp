#include <catch2/catch.hpp>

extern "C" {
#include "type_conversion.h"
}

// CWE-704: Incorrect Type Conversion
TEST_CASE("CWE-704: Incorrect Type Conversion", "[Ex324]") {
  int value = 0;
  int * ptr = &value;
#if 0
  REQUIRE(process(ptr) == ptr);
#endif
}
