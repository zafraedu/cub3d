#include "cub3d.h"

int	check_tures_space_tab(char **ture2d, int count)
{
	int	i;

	i = -1;
	if (count != 6)
		return (0);
	while (++i < count)
		if (!is_valid_texture(ture2d[i]))
			return (ft_putstr_fd(ERR_MAP_INV, 2), 0);
	return (1);
}

int	parse_rgb(char **ture2d)
{
	int		i;
	char	*ptr;

	i = 0;
	while (ture2d[i])
	{
		ptr = ture2d[i];
		while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
			ptr++;
		if (ptr[0] == 'F' || ptr[0] == 'C')
			if (count_comma(ptr) != 2 || !check_pos_cf(ptr))
				return (ft_putstr_fd(ERR_MAP_INV, 2), 0);
		i++;
	}
	return (1);
}

int	check_dup(t_data *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->ture2d[i])
	{
		j = i + 1;
		while (m->ture2d[j])
		{
			if (!ft_strncmp(m->ture2d[i], m->ture2d[j], 2))
				return (ft_putstr_fd(ERR_MAP_DUP, 2), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_first_last_line(char **map)
{
	if (!map[0])
		return (ft_putstr_fd(ERR_MAP_INV, 2), 0);
	if (!line_arond_one(map[0]) || !line_arond_one(getlastline(map)))
		return (ft_putstr_fd(ERR_MAP_INV, 2), 0);
	return (1);
}

int	surounded_by_one(char **map)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (map[i])
	{
		if (!is_surrounded(map[i]) || !is_validmap(map[i], &flag) || flag > 1)
			return (ft_putstr_fd(ERR_MAP_INV, 2), 0);
		i++;
	}
	if (flag == 0)
		return (ft_putstr_fd(ERR_MAP_INV, 2), 0);
	return (1);
}
