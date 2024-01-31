#include "cub3d.h"

void	ft_delete_tex(t_tex *tex)
{
	if (tex->no)
		mlx_delete_texture(tex->no);
	if (tex->so)
		mlx_delete_texture(tex->so);
	if (tex->we)
		mlx_delete_texture(tex->we);
	if (tex->ea)
		mlx_delete_texture(tex->ea);
}

void	ft_exit(t_mlx *mlx)
{
	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx_close_window(mlx->mlx_p);
	freelist(&mlx->dt->t);
	free_map(mlx->dt);
	ft_delete_tex(mlx->tex);
	free(mlx->tex);
	free(mlx->ply);
	free(mlx->ray);
	mlx_terminate(mlx->mlx_p);
	ft_putstr_fd("Game closed\n", 1);
	exit(0);
}
