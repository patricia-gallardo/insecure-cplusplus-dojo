// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include "string_length.hpp"
#include <catch2/catch.hpp>

TEST_CASE( "Calculating string length", "[hhgttg]" )
{
    // Null terminated string
    char str[] = "00112233445566";
    REQUIRE( stringLength(14, str) == 14 );
    
    // String not terminated
    str[14] = 42;
    REQUIRE( stringLength(14, str) == 14 );
    
    // Null terminated string
    char ten[] = "0123456789";
    REQUIRE( stringLength(10, ten) == 10 );
    
    // Null inserted
    ten[6] = 0;
    REQUIRE( stringLength(10, ten) == 6 );
}
