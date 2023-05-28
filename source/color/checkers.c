#include "../../include/cub3d.h"

int is_ceiling(char *cardinal, t_game *game)
{
    if (!ft_strncmp("C", cardinal, 2) && game->texture.ceiling == -1)
        return (1);
    return (0);
}

int is_floor(char *cardinal, t_game *game)
{
    if (!ft_strncmp("F", cardinal, 2) && game->texture.floor == -1)
        return (1);
    return (0);
}