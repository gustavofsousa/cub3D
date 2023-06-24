#ifndef STRUCT_H
# define STRUCT_H

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

typedef struct s_img
{
	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	cam_plane_dir_x;
	double	cam_plane_dir_y;
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

typedef struct s_data
{
	t_img			img;
	t_player		player;
	t_key_state		key;
	int				**map;
}	t_data;

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

#endif
