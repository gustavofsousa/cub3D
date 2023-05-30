#include "../../include/cub3d.h"

int is_wall_one(char *line, int begin, int end)
{
    while (begin < end)
    {
        if (line[begin++] != '1')
            return (0);
    }
    return (1);
}

int find_first_one(char *line)
{
    int i;

    i = 0;
    while (is_space(line[i]))
        i++;
    return (i);
}

// Tenho que ver onde começa o 1 no s1
// Tenho que ver onde começa o 1 no s2
// Ver qual dos dois é menor
// O que for menor eu vou incrementando e vendo se é 1 até chegar no maior
int validate_left(t_game *game)
{
    int     i;
    int     init_s1;
    int     init_s2;

    i = 0;
    while (game->map.mtx[++i])
    {
        init_s1 = find_first_one(game->map.mtx[i - 1]);
        init_s2 = find_first_one(game->map.mtx[i]);
        if (init_s1 < init_s2 && !is_wall_one(game->map.mtx[i - 1], init_s1, init_s2))
            return (0);
        else if (init_s1 > init_s2 && !is_wall_one(game->map.mtx[i], init_s2, init_s1))
            return (0);
    }
    return (1);
}