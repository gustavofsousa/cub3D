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

int    validate_right(t_game *game)
{
    int     i;
    char    *bigger_line;
    int     smaller_pos;
    char    **map;

    map = game->map.mtx;
    i = 0;
    while (map[++i])
    {
        bigger_line = max_str(map[i - 1], map[i]);
        smaller_pos = min_str_int(map[i - 1], map[i]);
        if (!is_all_wall(bigger_line, smaller_pos))
            return (0);
    }
    return (1);
}
