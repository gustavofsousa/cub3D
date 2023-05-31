#include "../../include/cub3d.h"

int is_valid_left_right(char c)
{
    if (c != '1' && c != ' ')
        return (0);
    return (1);
}

void    look_around(t_game *game, int i, int j)
{
    char    *previous_line;
    char    *next_line;
    char    previous_char;
    char    next_char;

    previous_line = game->map.mtx[i - 1];
    next_line = game->map.mtx[i + 1];
    previous_char = game->map.mtx[i][j - 1];
    next_char = game->map.mtx[i][j + 1];
    if (!is_valid_up_down(previous_line, j)
        || !is_valid_up_down(next_line, j)
        || !is_valid_left_right(previous_char)
        || !is_valid_left_right(next_char))
        exit_game("There's some hole in the middle map", game);
}

void    validate_middle(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map.mtx[++i + 1])
    {
        j = 0;
        while (game->map.mtx[i][++j + 1])
        {
            if (is_space(game->map.mtx[i][j]))
                look_around(game, i, j);
        }
    }
}