#include "../../include/cub3d.h"

void    validate_map(t_game *game)
{
    check_player_existence(game);
    check_hole_in_wall(game);

}