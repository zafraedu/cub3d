#include "cub3d.h"

// void	v(void)
// {
// 	system("leaks -q cub3d");
// }

/*############################################################################*/
int	main(int ac, char **av)
{
	t_data	dt;

	if (!parsing(ac, av, &dt))
		return (1);
	// start_the_game(data);  // start the game
	return (0);
}

// main of mini_cub
// int	main(void)
// {
// 	t_data *data;

// 	data = init_argumet(); // init the data structure
// 	start_the_game(data);  // start the game
// 	return (0);
// }
