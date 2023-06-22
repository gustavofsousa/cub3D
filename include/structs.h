#ifndef STRUCT_H
#define STRUCT_H

#include "constants.h"

typedef struct s_img
{
	int		height; // texture height, not initialized yet
	int		width; // texture width, not initialized yet
	void	*ptr; //mlx
	void	*win; //mlx_win
	void	*img;
	char	*addr;
	int		bpp; // bits_per_pixel
	int		line_len; //line_length
	int		endian;
}			t_img;

typedef struct s_map
{
	int		rows; // = n_rows
	int		cols; // = n_columns
	char	**mtx;
	int		**mtx_int;
}			t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	dirX; //E = 1 ; w = -1 ; N = 0 ; S = 0
	double	dirY; //E = 0 ; W =  0 ; N = -1; S = 1
	double	cam_plane_dirX;
	double	cam_plane_dirY;
	double	speed;
	double	rot_speed;
	int		dirx_pxl;
	int		diry_pxl;
}	t_player;

typedef struct s_key_state
{
	int	w_is_press;
	int	a_is_press;
	int	s_is_press;
	int	d_is_press;
}	t_key_state;

typedef struct s_int_vector
{
	int	x;
	int	y;
}	t_int_vector;

typedef struct s_double_vector
{
	double	x;
	double	y;
}	t_double_vector;

typedef struct	s_texture
{
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	int		floor;
	int		ceiling;
}				t_texture;

typedef struct s_ray_info
{
	t_double_vector	dir;
	t_double_vector	side;
	t_double_vector	delta;
	t_int_vector	step;
	t_int_vector	map_hit;
	int				side_hit;
	double			perp_wall_dist;
}	t_ray_info;

typedef struct	s_game
{
	t_img		img;
	t_map		map;
	t_ray_info		ray;
	t_player	player;
	t_texture	texture;
	t_key_state		key;
	int	tex_width; //delete after using texture files
	int	tex_height; //delete after using texture files
	int				tex[8][TEXTURE_HEIGHT * TEXTURE_WIDTH]; //delete after using texture files
	// int				**map; //delete after using texture files

}				t_game;
 
#endif
