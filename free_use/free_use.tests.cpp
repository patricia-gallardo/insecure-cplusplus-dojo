// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include "free_use.hpp"
#include <catch2/catch.hpp>

TEST_CASE( "Calculating string length", "[hhgttg]" )
{
    {
        char * buffer = make_buffer(4);
        REQUIRE( buffer != nullptr );
        free(buffer);
    }
    {
        char * buffer = make_buffer(5);
        REQUIRE( buffer != nullptr );
        free(buffer);
    }
}
