#include "cub3d.h"

void	get_rows_cols(t_data *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map2d[i])
	{
		j = 0;
		while (m->map2d[i][j])
			j++;
		if (j > m->cols)
			m->cols = j;
		i++;
	}
	m->rows = i;
}

void	get_x_y_player(t_data *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->sq_map[i])
	{
		j = 0;
		while (m->sq_map[i][j])
		{
			if (m->sq_map[i][j] == 'N' || m->sq_map[i][j] == 'S'
				|| m->sq_map[i][j] == 'W' || m->sq_map[i][j] == 'E')
			{
				m->p_x = j;
				m->p_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

/**
 * @return (Retorna 1 si dot no es NULL y la extensión es ".cub");
 * de lo contrario, retorna 0.
*/
int	check_extension_map(char *file_name)
{
	char	*dot;

	// Busca la última ocurrencia del carácter '.' en la cadena fname.
	dot = ft_strrchr(file_name, '.');
	return (dot && !ft_strcmp(dot, ".cub"));
}

int	parsing(int ac, char **av, t_data *data)
{
	int	count;

	if (ac != 2 || !check_extension_map(av[1]))
		return (ft_putstr_fd(ERR_INV_COP, 2), 0);
	count = 0;
	if (!read_map(av[1], data, &count))
		return (0);
	exit(1);
	data = NULL;
/* if (!valid_map(data))
		return (0);
	data->t = NULL;
	if (!lst_ture(data, &data->t))
		return (free_map(data), freelist(&data->t), 0);
	if (!color_ture(data, data->t))
		return (free_map(data), freelist(&data->t), 0);
	get_x_y_player(data);
	get_rows_cols(data); */
	return (1);
}
