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
