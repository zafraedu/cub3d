#include "cub3d.h"

/**
 * @return (Retorna 1 si dot no es NULL y la extensión es ".cub");
 * de lo contrario, retorna 0.
*/
int	checkextension(char *file_name)
{
	char	*dot;

	// Busca la última ocurrencia del carácter '.' en la cadena fname.
	dot = ft_strrchr(file_name, '.');
	return (dot && !ft_strcmp(dot, ".cub"));
}

int	parsing(int ac, char **av, t_data *data)
{
	int	count;

	if (ac != 2 || !checkextension(av[1]))
		return (ft_putstr_fd(ERR_INV_COP, 2), 0);
	count = 0;
	if (!read_map(av[1], data, &count))
		return (0);
	if (!valid_map(data))
		return (0);
	data->t = NULL;
	if (!lst_ture(data, &data->t))
		return (free_map(data), freelist(&data->t), 0);
	if (!color_ture(data, data->t))
		return (free_map(data), freelist(&data->t), 0);
	return (1);
}
