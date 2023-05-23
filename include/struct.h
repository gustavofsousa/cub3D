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

typedef struct	s_game
{
	int		*canvas;
}			t_game

#endif
