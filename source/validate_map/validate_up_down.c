#include "../../include/cub3d.h"

int    is_valid_up_down(char *line_updown, int pos)
{
    if (line_updown[pos] != '1' || line_updown[pos] != ' ')
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
        if (line[i] == ' ' && !is_valid_up_down(game->map.mtx[game->map.height - 2], i))
            return (0);
    }
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
        if (line[i] == ' ' && !is_valid_up_down(game->map.mtx[1], i))
            return (0);
    }
    return (1);
}
