#ifndef YATZY_INCLUDED
#define YATZY_INCLUDED

enum YatzyCategory { Chance, Yatzy, Ones, Twos, Threes, Fours, Fives, Sixes, Pair, TwoPairs,
                    ThreeOfAKind, FourOfAKind, SmallStraight, LargeStraight, FullHouse };

int answer(enum YatzyCategory category, 
           unsigned short first, 
           unsigned short second, 
           unsigned short third, 
           unsigned short fourth, 
           unsigned short fifth);

#endif
