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
 //# define M_PI 3.14159265358979323846 //? ns pq el de <math.h> no funciona

// ERROR

# define ERR_INV_COP "Error: invalid compilation\n"
# define ERR_INV_FILE "Error: invalid file\n"
# define ERR_EMPTY_FILE "Error: empty file\n"

# define ERR_MAP_INV "Error: invalid map element\n"
# define ERR_MAP_EMPTY "Error: empty ligne in the map\n"
# define ERR_MAP_DUP "Error: duplicate map element\n"
# define ERR_MAP_RGB "Error: color map [RGB] invalid\n"

/*══════════════════════════ [  STRUCTS  ] ═══════════════════════════════════*/

typedef struct s_turelist
{
	char				*name;
	char				*value;
	struct s_turelist	*next;
}						t_turelist;

typedef struct s_player
{
	int plyr_x;   // player x position in pixels
	int plyr_y;   // player y position in pixels
	double angle; // player angle
	float fov_rd; // field of view in radians
	int rot;      // rotation flag
	int l_r;      // left right flag
	int u_d;      // up down flag
}						t_player;

typedef struct s_ray
{
	double ray_ngl;  // ray angle
	double distance; // distance to the wall
	int flag;        // flag for the wall
}						t_ray;

typedef struct s_data
{
	char **map2d; // the map
	int p_x;      // player x position in the map
	int p_y;      // player y position in the map
	int w_map;    // map width
	int h_map;    // map height
	int					fd;
	char				*line;
	char				*ture;
	char				**ture2d;
	char				*map;
	char				**sq_map;
	char				**cc;
	char				**ff;
	int					cols;
	int					rows;
	t_turelist			*t;
}						t_data;

typedef struct s_mlx
{
	mlx_image_t *img; // the image
	mlx_t *mlx_p;     // the mlx pointer
	t_ray *ray;       // the ray structure
	t_data *dt;       // the data structure
	t_player *ply;    // the player structure
}						t_mlx;

/*═════════════════════════ [  FUNCTIONS  ] ══════════════════════════════════*/
/*-------------------------- [  parsing  ] -----------------------------------*/

// p_frees.c

void					freetl(char *ture, char *line, int fd);
void					free_map(t_data *m);
void					free_m(t_mlx *mlx);
void					freelist(t_turelist **head);

// p_lst_ture.c

int						get_index(char *line, int i);
t_turelist				*new_texture(char *line);
void					lst_back_ture(t_turelist **l_ture, t_turelist *new);
int						lst_ture(t_data *m, t_turelist **l_ture);

//p_read_map_utils.c

int						check_tures_space_tab(char **ture2d, int count);
int						parse_rgb(char **ture2d);
int						check_dup(t_data *m);
int						check_first_last_line(char **map);
int						surounded_by_one(char **map);

// p_read_map.c

int						is_surrounded(char *line);
int						is_validmap(char *line, int *flag);
char					*getmap(t_data *m);
int						read_map_(t_data *m, int count);
int						read_map(char *av, t_data *data, int *count);

// p_texture_utils.c

int						is_valid_texture(char *line);
int						count_comma(char *rgb);
int						check_pos_cf(char *line);
int						line_arond_one(char *line);
char					*getlastline(char **map);

// p_texture.c

int						check_color_values(char **rgb);
void					ft_process_rgb_color(t_turelist *tmp, t_data *m);
int						color_ture(t_data *m, t_turelist *l_ture);
int						check_color_textures(char *line);
int						check_count_textures(t_data *m, int count);

// p_valid_map.c

int						h_map(char **map);
int						v_map(char **map);
char					*fixline(char *line, int maxlen);
int						getsize_line(char **map);
int						valid_map(t_data *m);

// parsing.c

void					get_rows_cols(t_data *m);
void					get_x_y_player(t_data *m);
int						parsing(int ac, char **av, t_data *data);
int						check_extension_map(char *fname);

#endif
