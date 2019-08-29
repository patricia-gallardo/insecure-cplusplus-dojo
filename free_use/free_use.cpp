#include "free_use.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * make_buffer(int number)
{
    char *buffer = (char*) malloc(256);
    memset(buffer, 0, 256);

    switch (number) {
    case 5:
        free(buffer);
    case 4:
        printf("Pointer to buffer %p num chars %zu\n", buffer, strlen(buffer));
        break;
    default:
        break;
    }
    
    return buffer;
}