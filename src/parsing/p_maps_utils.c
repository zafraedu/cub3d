#include "cub3d.h"

int	is_surrounded(char *line)
{
	while (*line == 32 || (*line >= 9 && *line <= 13))
		line++;
	if (*line != '1' || line[ft_strlen(line) - 1] != '1')
		return (0);
	return (1);
}

int	is_validmap(char *line, int *flag)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] != '1' && line[i] != 32 && line[i] != '0'
				&& line[i] != '\n') && !(line[i] == 'W' || line[i] == 'E'
				|| line[i] == 'N' || line[i] == 'S'))
			return (0);
		else if (line[i] == 'W' || line[i] == 'E' || line[i] == 'N'
				|| line[i] == 'S')
			(*flag)++;
		i++;
	}
	return (1);
}
