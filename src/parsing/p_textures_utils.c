#include "cub3d.h"

int	is_valid_texture(char *line)
{
	while (*line == ' ' || (*line >= 9 && *line <= 13))
		line++;
	if ((!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		&& (line[2] == 32 || (line[2] >= 9 && line[2] <= 13)))
		return (1);
	else if ((!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
			&& (line[1] == 32 || (line[1] >= 9 && line[1] <= 13)))
		return (1);
	return (0);
}

int	count_comma(char *rgb)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (rgb[i])
		if (rgb[i++] == ',')
			count++;
	return (count);
}

int	check_pos_cf(char *l)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (*l == ' ' || (*l >= 9 && *l <= 13) || *l == 'C' || *l == 'F')
	{
		if (*l == 'C' || *l == 'F')
			flag++;
		l++;
	}
	if (flag != 1)
		return (0);
	if (!ft_isdigit(l[i]) || !ft_isdigit(l[(ft_strlen(l) - 1)]))
		return (0);
	while (l[i])
	{
		if ((!ft_isdigit(l[i]) && l[i] != ',') || (l[i] == ',' && l[i + 1]
				&& l[i + 1] == ','))
			return (0);
		i++;
	}
	return (1);
}

int	line_arond_one(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != '1' && line[i] != 32)
			return (0);
	return (1);
}

char	*getlastline(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (map[i - 1]);
}
