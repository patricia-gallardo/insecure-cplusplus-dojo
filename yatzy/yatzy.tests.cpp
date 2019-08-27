#include <gtest/gtest.h>

extern "C"
{
#include "yatzy.h"
}

using namespace ::testing;

TEST(Hiker, Life_the_universe_and_everything)
{
    ASSERT_EQ(14, answer(Chance, 1,1,3,3,6));
    //ASSERT_EQ(21, answer(Chance, 4,5,5,6,1));
    
    ASSERT_EQ(50, answer(Yatzy, 1,1,1,1,1));
    ASSERT_EQ(50, answer(Yatzy, 5,5,5,5,5));
    //ASSERT_EQ(0,  answer(Yatzy, 1,1,1,2,1));
    
    ASSERT_EQ(1, answer(Ones, 1,3,3,4,5));
    //ASSERT_EQ(0, answer(Ones, 2,3,3,4,5));

    ASSERT_EQ(4, answer(Twos, 2,3,2,5,1));
    //ASSERT_EQ(0, answer(Twos, 1,3,1,5,1));

    ASSERT_EQ(6, answer(Threes, 2,3,3,5,1));
    //ASSERT_EQ(0, answer(Threes, 2,2,2,5,1));

    ASSERT_EQ(8, answer(Fours, 1,1,2,4,4));
    //ASSERT_EQ(0, answer(Fours, 1,1,2,3,3));

    ASSERT_EQ(10, answer(Fives, 1,1,2,5,5));
    //ASSERT_EQ(0, answer(Fives, 1,1,2,4,4));

    ASSERT_EQ(18, answer(Sixes, 6,6,6,1,5));
    //ASSERT_EQ(0, answer(Sixes, 5,5,5,1,5));
    
    ASSERT_EQ(8, answer(Pair, 3,3,3,4,4));
    //ASSERT_EQ(12, answer(Pair, 1,1,6,2,6));
    //ASSERT_EQ(0, answer(Pair, 3,3,3,4,1));
    //ASSERT_EQ(0, answer(Pair, 3,3,3,3,1));
    
    ASSERT_EQ(8, answer(TwoPairs, 1,1,2,3,3));
    //ASSERT_EQ(0, answer(TwoPairs, 1,1,2,3,4));
    //ASSERT_EQ(0, answer(TwoPairs, 1,1,2,2,2));
    
    ASSERT_EQ(9, answer(ThreeOfAKind, 3,3,3,4,5));
    //ASSERT_EQ(0, answer(ThreeOfAKind, 3,3,4,5,6));
    //ASSERT_EQ(0, answer(ThreeOfAKind, 3,3,3,3,1));
    
    ASSERT_EQ(8, answer(FourOfAKind, 2,2,2,2,5));
    //ASSERT_EQ(0, answer(FourOfAKind, 2,2,2,5,5));
    //ASSERT_EQ(0, answer(FourOfAKind, 2,2,2,2,2));
    
    ASSERT_EQ(15, answer(SmallStraight, 1,2,3,4,5));
    //ASSERT_EQ(0, answer(SmallStraight, 2,2,2,2,5));
    
    ASSERT_EQ(20, answer(LargeStraight, 2,3,4,5,6));
    //ASSERT_EQ(0, answer(LargeStraight, 2,2,2,2,2));
    
    ASSERT_EQ(8, answer(FullHouse, 1,1,2,2,2));
    //ASSERT_EQ(0, answer(FullHouse, 2,2,3,3,4));
    //ASSERT_EQ(0, answer(FullHouse, 4,4,4,4,4));
}
