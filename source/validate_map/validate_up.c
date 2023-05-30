#include "../../include/cub3d.h"

int    is_valid_down(char *line_down, int pos)
{
    if (line_down[pos] != '1' || line_down[pos] != ' ')
        return (0);
    return (1);
}

int    validate_up(t_game *game)
{
    int     i;
    char    *line;

    line = game->map.mtx[0];
    i = -1;
    while (line[++i])
    {
        if (line[i] != '1' && line[i] != ' ')
            return (0);
        if (line[i] == ' ' && !is_valid_down(game->map.mtx[1], i))
            return (0);
    }
    return (1);
}
