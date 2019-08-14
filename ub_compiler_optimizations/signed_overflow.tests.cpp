// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include "signed_overflow.hpp"
#include <catch2/catch.hpp>

TEST_CASE( "Will it overflow?", "[hhgttg]" )
{
    REQUIRE( additionWillOverflow(INT_MAX, 256) );
}
