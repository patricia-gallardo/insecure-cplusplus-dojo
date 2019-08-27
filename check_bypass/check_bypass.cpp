#include "check_bypass.hpp"

bool bypassedCheckUnsigned(unsigned int first, unsigned int second)
{
    unsigned int max_sum = 256;
    
    if((first + second) <= max_sum)
      return true;
      
    return false;
}

bool bypassedCheckSigned(int first, int second)
{
    int max_sum = 256;
    
    if((first + second) <= max_sum)
      return true;
      
    return false;
}

bool bypassedCheckTruncated(unsigned int first, unsigned int second)
{
    unsigned int max_sum = 256;
    int sum = (first_len + second_len);

    if((first + second) <= max_sum)
      return true;

    return false;
}
