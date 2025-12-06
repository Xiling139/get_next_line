#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

//#define BUFFER_SIZE 4096

// Core function
char	*get_next_line(int fd);

/// GNL Utils
int get_len(char *buffer, int index);

#endif
