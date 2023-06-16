#ifndef CUB3D_H
#define CUB3D_H

#include <fcntl.h>
#include <stdio.h>
#include <math.h>

#include "../libft/libft.h"
#include "../mlx_Linux/mlx.h"

#include "structs.h"
#include "constants.h"

void render_game(t_data *data);
void setup_data(t_data *dat);
void setup_game(t_img *img);
void render_map2d(t_data *data, int square_sz);
void render_map3d(t_data *data);
void render_player(t_img *img, t_player player, int l);
void draw_line(t_img *img, int i[2], int f[2], int color);
void draw_vertical_line(t_img *img, int x, int y0, int yf, int color);
void draw_square(t_img *img, int x0, int y0, int color, int l);
void pixel_put(t_img *data, int x, int y, int color);
void walk_forward(t_data *data);
void walk_backward(t_data *data);
void walk_left(t_data *data);
void walk_right(t_data *data);
void setup_map(t_data *dat);

#endif