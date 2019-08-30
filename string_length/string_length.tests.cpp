// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include "string_length.hpp"
#include <catch2/catch.hpp>

TEST_CASE( "CWE-121: Access Outside Array Bounds", "[hhgttg]" )
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

TEST_CASE( "CWE-122: Write Outside Heap Array Bounds", "[hhgttg]" )
{
    // Null terminated string
    char str[] = "00112233445566";

    {
      char * copy = copyString(str, 14);
      REQUIRE( strnlen(copy, 14) == 14 );
      free(copy);
    }

    {
      // String not terminated
      str[14] = 42;
      char * copy = copyString(str, 14);
      REQUIRE( strnlen(copy, 14) == 14 );
      free(copy);
    }
}
