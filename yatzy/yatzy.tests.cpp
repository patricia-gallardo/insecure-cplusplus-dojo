// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include <catch2/catch.hpp>

extern "C"
{
#include "yatzy.h"
}

TEST_CASE( "Yatzy Rules", "[hhgttg]" )
{
    REQUIRE(14 == answer(Chance, 1,1,3,3,6));
    //REQUIRE(21 == answer(Chance, 4,5,5,6,1));
    
    REQUIRE(50 == answer(Yatzy, 1,1,1,1,1));
    REQUIRE(50 == answer(Yatzy, 5,5,5,5,5));
    //REQUIRE(0,  answer(Yatzy, 1,1,1,2,1));
    
    REQUIRE(1 == answer(Ones, 1,3,3,4,5));
    REQUIRE(4 == answer(Twos, 2,3,2,5,1));
    REQUIRE(6 == answer(Threes, 2,3,3,5,1));
    REQUIRE(8 == answer(Fours, 1,1,2,4,4));
    REQUIRE(10 == answer(Fives, 1,1,2,5,5));
    REQUIRE(18 == answer(Sixes, 6,6,6,1,5));
    
    REQUIRE(8 == answer(Pair, 3,3,3,4,4));
    //REQUIRE(12 == answer(Pair, 1,1,6,2,6));
    //REQUIRE(0 == answer(Pair, 3,3,3,4,1));
    //REQUIRE(0 == answer(Pair, 3,3,3,3,1));
    
    REQUIRE(8 == answer(TwoPairs, 1,1,2,3,3));
    //REQUIRE(0 == answer(TwoPairs, 1,1,2,3,4));
    //REQUIRE(0 == answer(TwoPairs, 1,1,2,2,2));
    
    REQUIRE(9 == answer(ThreeOfAKind, 3,3,3,4,5));
    //REQUIRE(0 == answer(ThreeOfAKind, 3,3,4,5,6));
    //REQUIRE(0 == answer(ThreeOfAKind, 3,3,3,3,1));
    
    REQUIRE(8 == answer(FourOfAKind, 2,2,2,2,5));
    //REQUIRE(0 == answer(FourOfAKind, 2,2,2,5,5));
    //REQUIRE(0 == answer(FourOfAKind, 2,2,2,2,2));
    
    REQUIRE(15 == answer(SmallStraight, 1,2,3,4,5));
    
    REQUIRE(20 == answer(LargeStraight, 2,3,4,5,6));
    
    REQUIRE(8 == answer(FullHouse, 1,1,2,2,2));
    //REQUIRE(0 == answer(FullHouse, 2,2,3,3,4));
    //REQUIRE(0 == answer(FullHouse, 4,4,4,4,4));
}
