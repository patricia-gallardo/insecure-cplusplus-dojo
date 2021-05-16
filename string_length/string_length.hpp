#ifndef STRING_LENGTH_INCLUDED
#define STRING_LENGTH_INCLUDED

#include <stdlib.h>
#include <string.h>

int stringLength(int size, const char *input);

char *copyString(const char *input, int size);

int containsChar(const char *input, char needle, size_t size);

#endif
