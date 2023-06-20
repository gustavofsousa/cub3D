#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_img
{
	int		height;
	int		width;
	void	*ptr;
	void	*win;
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_map
{
	int		height;
	int		width;
	char	**mtx;
	int		**mtx_int;
}			t_map;

typedef struct	s_ray
{

}				t_ray;

typedef struct	s_player
{
	int		x;
	int		y;
}				t_player;

typedef struct	s_texture
{
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	int		floor;
	int		ceiling;
}				t_texture;

typedef struct	s_game
{
	int			*canvas;
	t_img		mlx;
	t_map		map;
	t_ray		ray;
	t_player	player;
	t_texture	texture;
}				t_game;

#endif
