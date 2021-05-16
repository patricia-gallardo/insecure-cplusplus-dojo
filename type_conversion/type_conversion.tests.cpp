#include <gtest/gtest.h>

extern "C"
{
#include "type_conversion.h"
}

using namespace ::testing;

// CWE-704: Incorrect Type Conversion
TEST(CWE, Incorrect_Type_Conversion)
{
    int value = 0;
    int *ptr = &value;
    ASSERT_EQ( process(ptr), ptr );
}
