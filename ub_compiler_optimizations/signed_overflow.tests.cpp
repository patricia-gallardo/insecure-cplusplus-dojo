// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include "hiker.hpp"
#include <catch2/catch.hpp>

TEST_CASE( "Life the universe and everything", "[hhgttg]" )
{
    REQUIRE( answer() == 42 );
}
