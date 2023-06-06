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
  int play_x;
  int play_y;
} t_player;

typedef struct s_data
{
  t_img img;
  t_player player;
} t_data;

#endif