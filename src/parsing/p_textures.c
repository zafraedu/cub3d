#include "cub3d.h"

int	check_color_textures(char *line)
{
	while ((*line == ' ' || (*line >= 9 && *line <= 13)))
		line++;
	return ((!ft_strncmp(line, "EA", 2) || !ft_strncmp(line, "NO", 2) ||
				!ft_strncmp(line, "SO", 2) || !ft_strncmp(line, "WE", 2)) ||
			(!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1)));
}

int	check_count_textures(t_data *m, int count)
{
	if (count != 6)
	{
		ft_putstr_fd(ERR_MAP_INV, 2);
		ft_memfree(m->ture);
		ft_memfree(m->line);
		return (0);
	}
	return (1);
}
