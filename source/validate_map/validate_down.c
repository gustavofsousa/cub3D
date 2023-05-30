#include "../../include/cub3d.h"

int    is_valid_up(char *line_up, int pos)
{
    if (line_up[pos] != '1' || line_up[pos] != ' ')
        return (0);
    return (1);
}

int validate_down(t_game *game)
{
    int     i;
    char    *line;

    line = game->map.mtx[game->map.height - 1];
    i = -1;
    while (line[++i])
    {
        if (line[i] != '1' && line[i] != ' ')
            return (0);
        if (line[i] == ' ' && !is_valid_up(game->map.mtx[game->map.height - 2], i))
            return (0);
    }
    return (1);
}