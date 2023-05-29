#include "../../include/cub3d.h"


int	is_valid_player(char map_cell)
{
	if (ft_strchr("NSEW", map_cell) != 0)
        return (1);
    return (0);
}

void    validate_player(t_game *game)
{
    int i;
    int j;
    int qtd_player;

    qtd_player = 0;
    i = -1;
    while (game->map.mtx[++i])
    {
        j = -1;
        while (game->map.mtx[i][++j])
        {
            if (is_valid_player(game->map.mtx[i][j]))
            {
                game->player.x = j;
                game->player.y = i;
                qtd_player++;
            }
        }
    }
    if (qtd_player != 1)
        exit_game("Incorrect number of player", game);
}