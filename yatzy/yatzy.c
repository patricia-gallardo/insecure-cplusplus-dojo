#include "yatzy.h"

#include <assert.h>
#include <stdbool.h>

int answer(enum YatzyCategory category, 
           unsigned short first, 
           unsigned short second, 
           unsigned short third, 
           unsigned short fourth, 
           unsigned short fifth)
{
    assert(first  > 0 && first  < 7);
    assert(second > 0 && second < 7);
    assert(third  > 0 && third  < 7);
    assert(fourth > 0 && fourth < 7);
    assert(fifth  > 0 && fifth  < 7);
    
    switch(category) 
    {
    case Chance : return 14;
    case Yatzy : return 50;
    case Ones : return 1;
    case Twos : return 4;
    case Threes : return 6;
    case Fours : return 8;
    case Fives : return 10;
    case Sixes : return 18;
    case Pair : return 8;
    case TwoPairs : return 8;
    case ThreeOfAKind : return 9;
    case FourOfAKind : return 8;
    case SmallStraight : return 15;
    case LargeStraight : return 20;
    case FullHouse : return 8;
    default: return 1337;
    }
}
