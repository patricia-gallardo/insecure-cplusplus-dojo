#include "signed_overflow.hpp"

bool additionWillOverflow(int first, int second)
{
    return first + second < 0;
}
