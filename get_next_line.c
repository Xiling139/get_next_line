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

char *get_next_line(int fd)
{
    char buffer[4096];
    char *line;
    static int index = 0;
    int i = 0;
    
    read(fd, buffer, 4096);
    line = (char *)malloc(sizeof(char) * (get_len(buffer, index) + 1));
    if (!line)
        return (NULL);
    while (i < 4096)
    {
        if (buffer[index] == '\n') {
            line[i] = '\n';
            index++;
            break;
        }
        else 
            line[i] = buffer[index];
        i++;
        index++;
    }
    line[i] = '\0';
    return(line);
}

#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("heheheha.txt", O_RDONLY);
    if (fd == -1)
        return (-1);
    for (int i = 0; i < 5; i++) {
        char *s = get_next_line(fd);
        printf("%s", s);
        free(s);
    }
    close(fd);
}