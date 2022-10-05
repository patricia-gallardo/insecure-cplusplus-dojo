#include <gtest/gtest.h>

extern "C" {
#include "heartbleed.h"
}

using namespace ::testing;

TEST(Heartbleed, Returns_the_buffer_on_valid_request) {

  const int request_type_len = 1;
  const int size_len = 2;
  const int payload_len = 7;
  const int padding_len = 16;
  int valid_len = request_type_len + size_len + payload_len + padding_len;

  unsigned char valid_request[valid_len];
  valid_request[0] = '\x01'; // Request type is 1
  valid_request[1] = '\x00'; // Size
  valid_request[2] = '\x07'; // Size = 7 bytes
  valid_request[3] = '\x41'; // Payload byte 0
  valid_request[4] = '\x42'; // Payload byte 1
  valid_request[5] = '\x43'; // Payload byte 2
  valid_request[6] = '\x44'; // Payload byte 3
  valid_request[7] = '\x45'; // Payload byte 4
  valid_request[8] = '\x46'; // Payload byte 5
  valid_request[9] = '\x47'; // Payload byte 6

  ASSERT_EQ(valid_len, 26);

  char * response = nullptr;
  ASSERT_EQ(0, heartbleed(valid_request, valid_len, &response));
  ASSERT_NE(nullptr, response);

  ASSERT_EQ('\x02', response[0]); // Response type is 2
  ASSERT_EQ('\x00', response[1]); // Size
  ASSERT_EQ('\x07', response[2]); // Size = 7 bytes
  ASSERT_EQ('\x41', response[3]); // Payload byte 0
  ASSERT_EQ('\x42', response[4]); // Payload byte 1
  ASSERT_EQ('\x43', response[5]); // Payload byte 2
  ASSERT_EQ('\x44', response[6]); // Payload byte 3
  ASSERT_EQ('\x45', response[7]); // Payload byte 4
  ASSERT_EQ('\x46', response[8]); // Payload byte 5
  ASSERT_EQ('\x47', response[9]); // Payload byte 6

  free(response);
}

#if 0
TEST(Heartbleed, Does_not_leak_info_small)
{
  unsigned char short_request[] = "\x01\x01\xfd\x00";
  int short_len = sizeof(short_request)/sizeof(short_request[0]);
  ASSERT_EQ(short_len, 5);

    char * response = nullptr;
    ASSERT_EQ(0, heartbleed(short_request, short_len, &response));
    ASSERT_EQ(nullptr, response);
}

TEST(Heartbleed, Does_not_leak_info_large)
{
  unsigned char long_request[] = "\x01\x01\xfd\xde\xad\xbe\xef\xde\xad\xbe\xef\xde\xad\xbe\xef\xde\xad\xbe\xef\x00";
  int long_len = sizeof(long_request)/sizeof(long_request[0]);
  ASSERT_EQ(long_len, 21);

    char * response = nullptr;
    ASSERT_EQ(0, heartbleed(long_request, long_len, &response));
    ASSERT_EQ(nullptr, response);
}
#endif
