#include "cub3d.h"

// void leaks(void)
// {
// 	system("leaks -q cub3D");
// }
// atexit(leaks);

int	main(int ac, char **av)
{
	t_data	dt;

	if (!parsing(ac, av, &dt))
		return (1);
	execution(&dt);
	free_map(&dt);
	freelist(&dt.t_list);
	return (0);
}
