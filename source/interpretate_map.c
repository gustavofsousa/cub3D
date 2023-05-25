#include "../include/cub3d.h"

void    interpretate_map(t_game *game)
{
    open(file_path);
    while (42)
    {
        game->map.mtx[i] = get_nl(file_path);
        possible_errors();
        game->map.height++;
        if (game->map.mtx[i] == NULL)
            break ;
    }
}