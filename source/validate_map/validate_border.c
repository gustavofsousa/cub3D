#include "../../include/cub3d.h"

void    validate_border(t_game *game)
{
    if (!validate_up(game)
        || !validate_down(game)
        || !validate_left(game)
        || !validate_right(game))
        exit_game("it's just another brick in the wall", game);
}