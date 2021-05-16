// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include "string_length.hpp"
#include <catch2/catch.hpp>

#define CWE121_1
//#define CWE121_2
#define CWE121_3
//#define CWE121_4

TEST_CASE("CWE-121: Access Outside Array Bounds", "[hhgttg]") {
#ifdef CWE121_1
  // Null terminated string
  char str[] = "00112233445566";
  REQUIRE(stringLength(14, str) == 14);
#endif

#ifdef CWE121_2
  // String not terminated
  str[14] = 42;
  REQUIRE(stringLength(14, str) == 14);
#endif

#ifdef CWE121_3
  // Null terminated string
  char ten[] = "0123456789";
  REQUIRE(stringLength(10, ten) == 10);
#endif

#ifdef CWE121_4
  // Null inserted
  ten[6] = 0;
  REQUIRE(stringLength(10, ten) == 6);
#endif
}

//#define CWE122_1
//#define CWE122_2

TEST_CASE("CWE-122: Write Outside Heap Array Bounds", "[hhgttg]") {
#if defined(CWE122_1) || defined(CWE122_2)
  // Null terminated string
  char str[] = "00112233445566";
#endif

#ifdef CWE122_1
  {
    char * copy = copyString(str, 14);
    REQUIRE(strnlen(copy, 14) == 14);
    free(copy);
  }
#endif

#ifdef CWE122_2
  {
    // String not terminated
    str[14] = 42;
    char * copy = copyString(str, 14);
    REQUIRE(strnlen(copy, 14) == 14);
    free(copy);
  }
#endif
}

#define CWE124_1
//#define CWE124_2
//#define CWE124_3

TEST_CASE("CWE-124: Write Before Array Bounds", "[hhgttg]") {
#ifdef CWE124_1
  {
    char str[] = "001122:33445566";
    REQUIRE(containsChar(str, ':', 15) == 7);
  }
#endif

#ifdef CWE124_2
  {
    char str[] = "";
    REQUIRE(containsChar(str, ':', 0) == -1);
  }
#endif

#ifdef CWE124_3
  {
    char str[] = "00112233445566";
    REQUIRE(containsChar(str, ':', 14) == -1);
  }
#endif
}
