#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_img
{
	void *img;
	char *addr;
	void *mlx;
	void *mlx_win;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_img;

typedef struct s_player
{
	double	play_x;
	double	play_y;
	double	dirX;
	double	dirY;
	double	cam_plane_dirX;
	double	cam_plane_dirY;
	double	speed;
	double	rot_speed;
} t_player;

typedef struct s_key_state
{
	int		w_is_press;
	int		a_is_press;
	int		s_is_press;
	int		d_is_press;
} t_key_state;


typedef struct s_data
{
	t_img img;
	t_player player;
	t_key_state key;
} t_data;

#endif