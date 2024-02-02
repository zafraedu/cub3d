#include "cub3d.h"

int	is_surrounded(char *line)
{
	while (ft_isspace(*line))
		line++;
	return (*line == '1' && line[ft_strlen(line) - 1] == '1');
}

int	is_validmap(char *line, int *flag)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if ((line[i] != '1' && line[i] != 32 && line[i] != '0'
				&& line[i] != '\n') && !(line[i] == 'W' || line[i] == 'E'
				|| line[i] == 'N' || line[i] == 'S'))
			return (0);
		else if (line[i] == 'W' || line[i] == 'E' || line[i] == 'N'
			|| line[i] == 'S')
			(*flag)++;
	}
	return (1);
}

char	*getmap(t_data *map)
{
	char	*temp;

	map->map = ft_strdup("");
	while (map->line)
	{
		if (map->line[0] == '\n')
			return (ft_putstr_fd(ERR_MAP_EMPTY, 2), freetl(map->map, map->line,
					-1), NULL);
		temp = ft_strjoin(map->map, map->line);
		ft_memfree(map->map);
		ft_memfree(map->line);
		map->map = ft_strdup(temp);
		ft_memfree(temp);
		map->line = get_next_line(map->fd);
	}
	return (map->map);
}

int	read_map_(t_data *map, int count)
{
	map->map = getmap(map);
	if (!map->map)
		return (0);
	map->map2d = ft_split(map->map, '\n');
	if (!map->map2d)
		return (ft_memfree(map->map), 0);
	ft_memfree(map->map);
	if (!check_tures_space_tab(map->ture2d, count) || !parse_rgb(map->ture2d)
		|| !check_dup(map) || !check_first_last_line(map->map2d)
		|| !surounded_by_one(map->map2d))
		return (free2d(map->map2d), 0);
	return (1);
}

void	process_map(t_data *map, int *count)
{
	char	*temp_ture;

	while (map->line && map->line[0] != '1' && map->line[0] != 32)
	{
		if (check_color_textures(map->line))
		{
			temp_ture = ft_strjoin(map->ture, map->line);
			ft_memfree(map->ture);
			map->ture = strdup(temp_ture);
			ft_memfree(temp_ture);
			(*count)++;
		}
		ft_memfree(map->line);
		map->line = get_next_line(map->fd);
	}
}

int	read_map(char *av, t_data *map, int *count)
{
	map->fd = open(av, O_RDONLY);
	if (map->fd == -1)
		return (ft_putstr_fd(ERR_INV_FILE, 2), 0);
	map->line = get_next_line(map->fd);
	if (map->line == NULL)
		return (ft_putstr_fd(ERR_EMPTY_FILE, 2), 0);
	map->ture = ft_strdup("");
	process_map(map, count);
	if (!check_count_textures(map, *count))
		return (freetl(map->ture, map->line, map->fd), 0);
	map->ture2d = ft_split(map->ture, '\n');
	if (!map->ture2d)
		return (freetl(map->ture, map->line, map->fd), 0);
	if (!read_map_(map, *count))
		return (freetl(map->ture, map->line, map->fd), free2d(map->ture2d), 0);
	return (freetl(map->ture, map->line, map->fd), 1);
}
