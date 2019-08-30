#include "string_length.hpp"

int stringLength(int size, const char *input)
{
  return strlen(input);
}

char * copyString(const char *input, int size)
{
  char *buf = (char *) malloc(sizeof(char)*size);
  strcpy(buf, input);
  return buf;
}

int containsChar(const char *input, char needle, size_t size)
{
  char buf[size];
  strncpy(buf, input, size);
  buf[size-1] = '\0';
  int index = (strnlen(buf, size) - 1);
  while (buf[index] != needle)
    buf[index--] = '\0';
  return index + 1;
}
