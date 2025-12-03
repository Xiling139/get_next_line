#include "get_next_line.h"

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
    while (buffer[index])
    {
        if (buffer[index] == '\n') {
            line[i] = '\n';
            i++;
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
    if (fd == -1){
        printf("File not found!\n");
        return (-1);    
    }
    for (int i = 0; i < 5; i++) {
        char *s = get_next_line(fd);
        printf("%s", s);
        free(s);
    }
    close(fd);
}