// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include "check_bypass.hpp"
#include <catch2/catch.hpp>

TEST_CASE( "CWE-190: Integer Overflow or Wraparound", "[hhgttg]" )
{
    // Unsigned : Small enough
    REQUIRE( bypassedCheckUnsigned(42, 42) );
    // Unsigned : Too big
    REQUIRE( !bypassedCheckUnsigned(256, 256) );
    
    // --------------------------------------------
    // Unsigned : Bypass check
    //REQUIRE( bypassedCheckUnsigned(<FIRST>, <SECOND>) );
    // --------------------------------------------
    
    // Signed : Small enough
    REQUIRE( bypassedCheckSigned(42, 42) );
    // Signed : Too big
    REQUIRE( !bypassedCheckSigned(256, 256) );
    
    // --------------------------------------------
    // Signed : Bypass check
    //REQUIRE( bypassedCheckSigned(<FIRST>, <SECOND>) );
    // --------------------------------------------
}
