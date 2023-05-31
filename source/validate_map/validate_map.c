#include "../../include/cub3d.h"

void    validate_map(t_game *game)
{
    validate_char(game);
    validate_player(game);
    validate_border(game);
    validate_middle(game);
}