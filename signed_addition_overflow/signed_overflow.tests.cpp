// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include "signed_overflow.hpp"
#include <catch2/catch.hpp>

TEST_CASE("CWE-190: Signed Integer Addition Overflow", "[Ex321]") {
  // REQUIRE(additionWillOverflow(INT_MAX, 256));

  // REQUIRE( !additionWillOverflow(INT_MAX, 0) );

  // REQUIRE( !additionWillOverflow(0, INT_MAX) );

  // REQUIRE( !additionWillOverflow(256, 256) );

  // REQUIRE( additionWillOverflow(INT_MAX-1, INT_MAX-1) );

  // REQUIRE( additionWillOverflow(-42, INT_MIN) );

  // REQUIRE( additionWillOverflow(INT_MIN, -42) );

  // REQUIRE( !additionWillOverflow(INT_MAX-256, 256) );
}
