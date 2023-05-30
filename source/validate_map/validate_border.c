#include "../../include/cub3d.h"

int    is_all_wall(char *line, int pos)
{
    while (line[pos])
        if (line[pos++] != '1')
            return (0);
    return (1);
}

int    min_str_int(char *s1, char *s2)
{
    int len_s1;
    int len_s2;

    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    if (len_s1 < len_s2)
        return (len_s1);
    return (len_s2);
}

char    *max_str(char *s1, char *s2)
{
    int len_s1;
    int len_s2;

    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    if (len_s1 > len_s2)
        return (s1);
    return (s2);
}

void    validate_per_line(t_game *game, char **map)
{
    int     i;
    char    *bigger_line;
    int     smaller_pos;
 

    i = 0;
    while (map[++i])
    {
        bigger_line = max_str(map[i - 1], map[i]);
        smaller_pos = min_str_int(map[i - 1], map[i]);
        if (!is_all_wall(bigger_line, smaller_pos))
            exit_game("it's just another brick in the wall", game);
    }

}

// a prmeira linha precisa ser 1
// Vejo se o primeiro char deopis do espaço de toda linha é 1.
// próxima linha vou até a posição de quem for maior
// Vejo na linha menor se nessa ultima posição tem 1.
// Vou olhando na linha maior até chegar ao fim se só tem 1.
void    validate_border(t_game *game)
{
    //validate_first_col(game);
    //validate_first_line(game);
    validate_per_line(game, game->map.mtx);
}