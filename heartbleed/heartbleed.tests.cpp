#include <gtest/gtest.h>

extern "C"
{
#include "heartbleed.h"
}

using namespace ::testing;

void print_buffer(const char *buffer, int len) {
  printf("Buffer (%d bytes) : ", len);
  for (int i = 0; i < len; i++) {
    printf("x\\%02x", buffer[i]);
  }
  printf("\n");
}

TEST(Heartbleed, Does_not_leak_info_small)
{
    char short_request[] = "\x01\x01\xfd\x00";
    int short_len = strlen(short_request);

    char * response = NULL;
    ASSERT_EQ(0, heartbleed(short_request, short_len, &response));
    ASSERT_EQ(NULL, response);
    if (response) print_buffer(response, short_len);
}

TEST(Heartbleed, Does_not_leak_info_large)
{
    char long_request[] = "\x01\x01\xfd\xde\xad\xbe\xef\xde\xad\xbe\xef\xde\xad\xbe\xef\xde\xad\xbe\xef\x00";
    int long_len = strlen(long_request);

    char * response = NULL;
    ASSERT_EQ(0, heartbleed(long_request, long_len, &response));
    ASSERT_EQ(NULL, response);
    if (response) print_buffer(response, long_len);
}
