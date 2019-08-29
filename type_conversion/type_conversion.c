#include "type_conversion.h"

#include <inttypes.h>

int * process(int * ptr)
{
    int pointer = (intptr_t) ptr;
    return (int *) pointer;
}