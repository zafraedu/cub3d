#ifndef CUB3D_H
# define CUB3D_H

/*═════════════════════════════ [  LIBS  ] ═══════════════════════════════════*/

// personal libs
# include "../lib/libft/inc/libft.h"
# include "../lib/libmlx/include/MLX42/MLX42.h"
// global libs
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <limits.h>
# include <math.h>
# include <memory.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

/*═══════════════════════════ [  MACROS  ] ═══════════════════════════════════*/

// MLX - GAME

# define S_W 1900                    // screen width
# define S_H 1000                    // screen height
# define TILE_SIZE 30                // tile size
# define FOV 60                      // field of view
# define ROTATION_SPEED 0.045        // rotation speed
# define PLAYER_SPEED 4              // player speed
# define M_PI 3.14159265358979323846 //? ns pq el de <math.h> no funciona

// ERROR

# define ERR_INV_COP "Error: invalid compilation\n"
# define ERR_INV_FILE "Error: invalid file\n"
# define ERR_EMPTY_FILE "Error: empty file\n"

# define ERR_MAP_INV "Error: invalid map element\n"
# define ERR_MAP_EMPTY "Error: empty ligne in the map\n"
# define ERR_MAP_DUP "Error: duplicate map element\n"

/*══════════════════════════ [  STRUCTS  ] ═══════════════════════════════════*/

typedef struct s_player
{
	int plyr_x;   // player x position in pixels
	int plyr_y;   // player y position in pixels
	double angle; // player angle
	float fov_rd; // field of view in radians
	int rot;      // rotation flag
	int l_r;      // left right flag
	int u_d;      // up down flag
}			t_player;

typedef struct s_ray
{
	double ray_ngl;  // ray angle
	double distance; // distance to the wall
	int flag;        // flag for the wall
}			t_ray;

typedef struct s_data
{
	char **map2d; // the map
	int p_x;      // player x position in the map
	int p_y;      // player y position in the map
	int w_map;    // map width
	int h_map;    // map height
	int		fd;
	char	*line;
	char	*ture;
	char	**ture2d;
	char	*map;
}			t_data;

typedef struct s_mlx
{
	mlx_image_t *img; // the image
	mlx_t *mlx_p;     // the mlx pointer
	t_ray *ray;       // the ray structure
	t_data *dt;       // the data structure
	t_player *ply;    // the player structure
}			t_mlx;

/*═════════════════════════ [  FUNCTIONS  ] ══════════════════════════════════*/
/*------------------------- [  Mini cub  ] -----------------------------------*/

// exit.c

void		ft_exit(t_mlx *mlx);

// mouvement.c

void		ft_reles(mlx_key_data_t keydata, t_mlx *mlx);
void		mlx_key(mlx_key_data_t keydata, void *ml);
void		rotate_player(t_mlx *mlx, int i);
void		move_player(t_mlx *mlx, double move_x, double move_y);
void		hook(t_mlx *mlx, double move_x, double move_y);

// wall_rendering.c

void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
float		nor_angle(float angle);
void		draw_floor_ceiling(t_mlx *mlx, int ray, int t_pix, int b_pix);
int			get_color(t_mlx *mlx, int flag);
void		draw_wall(t_mlx *mlx, int ray, int t_pix, int b_pix);
void		render_wall(t_mlx *mlx, int ray);

// raycasting.c

int			unit_circle(float angle, char c);
int			inter_check(float angle, float *inter, float *step, int is_horizon);
int			wall_hit(float x, float y, t_mlx *mlx);
float		get_h_inter(t_mlx *mlx, float angl);
float		get_v_inter(t_mlx *mlx, float angl);
void		cast_rays(t_mlx *mlx);

// game_start.c

void		game_loop(void *ml);
void		init_the_player(t_mlx mlx);
void		start_the_game(t_data *dt);

// init_argument.c

t_data		*init_argumet(void);

/*-------------------------- [  parsing  ] -----------------------------------*/

// p_frees.c

void		freetl(char *ture, char *line, int fd);

// p_maps_utils.c

int			is_surrounded(char *line);
int			is_validmap(char *line, int *flag);

// p_maps.c

char		*getmap(t_data *m);
int			read_map_(t_data *m, int count);
int			read_map(char *av, t_data *data, int *count);

//p_read_map_utils.c

int			check_tures_space_tab(char **ture2d, int count);
int			parse_rgb(char **ture2d);
int			check_dup(t_data *m);
int			check_first_last_line(char **map);
int			surounded_by_one(char **map);

// p_texture_utils.c

int			is_valid_texture(char *line);
int			count_comma(char *rgb);
int			check_pos_cf(char *line);
int			line_arond_one(char *line);
char		*getlastline(char **map);

// p_texture.c

int			check_count_textures(t_data *m, int count);
int			check_color_textures(char *line);

// parsing_utils.c

// parsing.c

int			parsing(int ac, char **av, t_data *data);
int			checkextension(char *fname);

// main.c //test - ns donde poner

#endif
