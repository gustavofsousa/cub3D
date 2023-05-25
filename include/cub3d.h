#ifndef CUB3D_H
#define CUB3D_H

# include "../libft/libft.h"
# include "structs.h"
# include "../mlx_linux/mlx.h"
//# include "../miniLibX/mlx.h"

#define LENGHT 200
#define HEIGHT 200

void    setup(t_game *game);
void    interpretate_map(t_game *game);
void    validate_map(t_game *game);
void    render_game(t_game *game);

#endif
