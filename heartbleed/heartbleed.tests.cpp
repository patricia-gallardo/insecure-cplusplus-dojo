#include <catch2/catch.hpp>

extern "C" {
#include "heartbleed.h"
}

TEST_CASE("Heartbleed: Returns the buffer on valid_request", "[hhgttg]") {

  const int request_type_len = 1;
  const int size_len = 2;
  const int payload_len = 7;
  const int padding_len = 16;
  const int valid_len = request_type_len + size_len + payload_len + padding_len;

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

  REQUIRE(valid_len == 26);

  char * response = nullptr;
  REQUIRE(0 == heartbleed(valid_request, valid_len, &response));
  REQUIRE(nullptr != response);

  REQUIRE('\x02' == response[0]); // Response type is 2
  REQUIRE('\x00' == response[1]); // Size
  REQUIRE('\x07' == response[2]); // Size = 7 bytes
  REQUIRE('\x41' == response[3]); // Payload byte 0
  REQUIRE('\x42' == response[4]); // Payload byte 1
  REQUIRE('\x43' == response[5]); // Payload byte 2
  REQUIRE('\x44' == response[6]); // Payload byte 3
  REQUIRE('\x45' == response[7]); // Payload byte 4
  REQUIRE('\x46' == response[8]); // Payload byte 5
  REQUIRE('\x47' == response[9]); // Payload byte 6

  free(response);
}

#if 0
TEST_CASE("Heartbleed: Does not leak info small", "[hhgttg]") {

  unsigned char short_request[] = "\x01\x01\xfd\x00";
  int short_len = sizeof(short_request)/sizeof(short_request[0]);
  REQUIRE(short_len == 5);

    char * response = nullptr;
    REQUIRE(0 == heartbleed(short_request, short_len, &response));
    REQUIRE(nullptr == response);
}

TEST_CASE("Heartbleed: Does not leak info large", "[hhgttg]") {

  unsigned char long_request[] = "\x01\x01\xfd\xde\xad\xbe\xef\xde\xad\xbe\xef\xde\xad\xbe\xef\xde\xad\xbe\xef\x00";
  int long_len = sizeof(long_request)/sizeof(long_request[0]);
  REQUIRE(long_len == 21);

    char * response = nullptr;
    REQUIRE(0 == heartbleed(long_request, long_len, &response));
    REQUIRE(nullptr == response);
}
#endif
