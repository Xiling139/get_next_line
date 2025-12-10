#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*s = "";

	fd = open("test_tier_1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("File not found!\n");
		return (-1);
	}
	while(s != NULL)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
	}
	close(fd);
}
