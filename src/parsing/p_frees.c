#include "cub3d.h"

void	freetl(char *ture, char *line, int fd)
{
	if (ture)
		free(ture);
	if (line)
		free(line);
	if (fd > 0)
		close (fd);
}
