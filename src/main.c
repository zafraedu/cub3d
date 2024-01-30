#include "cub3d.h"

void	v(void)
{
	system("leaks -q cub3D");
}

// void imprimirMatriz(char **matriz, int filas, int columnas) {
//     for (int i = 0; i < filas; i++) {
//         for (int j = 0; j < columnas; j++) {
//             printf("%c ", matriz[i][j]);
//         }
//         printf("\n");
//     }
// }
// imprimirMatriz(dt.sq_map, dt.h_map, dt.w_map);

/*############################################################################*/
int	main(int ac, char **av)
{
	atexit(v);
	t_data	dt;
	dt.t = NULL;
	if (!parsing(ac, av, &dt))
		return (1);
	// execution(&dt);
	return (0);
}
