#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("heheheha.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("File not found!\n");
		return (-1);
	}
	for (int i = 0; i < 5; i++)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
	}
	close(fd);
}
