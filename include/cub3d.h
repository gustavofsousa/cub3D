#ifndef CUB3D_H
#define CUB3D_H

#include <fcntl.h>
#include <stdio.h>

#include "../libft/libft.h"
#include "../mlx_Linux/mlx.h"

#include "structs.h"
#include "constants.h"

void	render_game(void);
void	draw_line(t_img *img, int i[2], int f[2]);
void	pixel_put(t_img *data, int x, int y, int color);

#endif