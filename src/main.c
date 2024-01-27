#include "cub3d.h"

// void	v(void)
// {
// 	system("leaks -q cub3d");
// }

/*############################################################################*/
int	main(int ac, char **av)
{
	t_data	dt;

	dt.t = NULL;
	if (!parsing(ac, av, &dt))
		return (1);
	// start_the_game(data);  // start the game
	execution(&dt);
	return (0);
}
