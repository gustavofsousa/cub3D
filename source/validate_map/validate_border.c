#include "../../include/cub3d.h"

// a prmeira linha precisa ser 1
// Vejo se o primeiro char deopis do espaço de toda linha é 1.
// próxima linha vou até a posição de quem for maior
// Vejo na linha menor se nessa ultima posição tem 1.
// Vou olhando na linha maior até chegar ao fim se só tem 1.
void    validate_border(t_game *game)
{
    if (!validate_up(game)
        || !validate_down(game)
        || !validate_left(game)
        || !validate_right(game))
        exit_game("it's just another brick in the wall", game);
    //validate_middle(game);
}