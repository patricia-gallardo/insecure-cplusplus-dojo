#include <gtest/gtest.h>

extern "C"
{
#include "heartbleed.h"
}

using namespace ::testing;

TEST(Heartbleed, Returns_the_buffer_on_valid_request)
{
    const int valid_len = 7;

    char valid_request[valid_len];
    valid_request[0] = '\x01'; // Response type is 1
    valid_request[1] = '\x00'; // Size
    valid_request[2] = '\x07'; // Size = 7 bytes
    valid_request[3] = '\xde'; // Payload byte 0
    valid_request[4] = '\xad'; // Payload byte 1
    valid_request[5] = '\xbe'; // Payload byte 2
    valid_request[6] = '\xef'; // Payload byte 3

    char * response = NULL;
    ASSERT_EQ(0, heartbleed(valid_request, valid_len, &response));
    ASSERT_NE(nullptr, response);

    ASSERT_EQ('\x02', response[0]); // Response type is 2
    ASSERT_EQ('\x00', response[1]); // Size
    ASSERT_EQ('\x07', response[2]); // Size = 7 bytes
    ASSERT_EQ('\xde', response[3]); // Payload byte 0
    ASSERT_EQ('\xad', response[4]); // Payload byte 1
    ASSERT_EQ('\xbe', response[5]); // Payload byte 2
    ASSERT_EQ('\xef', response[6]); // Payload byte 3
}

#if 0
TEST(Heartbleed, Does_not_leak_info_small)
{
    char short_request[] = "\x01\x01\xfd\x00";
    int short_len = strlen(short_request);

    char * response = NULL;
    ASSERT_EQ(0, heartbleed(short_request, short_len, &response));
    ASSERT_EQ(NULL, response);
}

TEST(Heartbleed, Does_not_leak_info_large)
{
    char long_request[] = "\x01\x01\xfd\xde\xad\xbe\xef\xde\xad\xbe\xef\xde\xad\xbe\xef\xde\xad\xbe\xef\x00";
    int long_len = strlen(long_request);

    char * response = NULL;
    ASSERT_EQ(0, heartbleed(long_request, long_len, &response));
    ASSERT_EQ(NULL, response);
}
#endif
