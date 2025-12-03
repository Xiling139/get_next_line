#include "get_next_line.h"

int get_len(char *buffer, int index)
{
    int count = 0;
    
    while(buffer[index + count] && buffer[index + count] != '\n')
    {
        count++;
    }
    return (count);
}