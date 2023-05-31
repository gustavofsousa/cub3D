#include "../../include/cub3d.h"

int is_valid_wall(char *line, int begin, int end)
{
    while (begin < end)
    {
        if (line[begin] != '1' && line[begin] != ' ')
            return (0);
        begin++;
    }
    return (1);
}

int find_init_line(char *line)
{
    int i;

    i = 0;
    while (is_space(line[i]))
        i++;
    return (i);
}

int is_valid_at_pos(char *s1, char *s2, int init_s1, int init_s2)
{
    if (s1[init_s1] == '0' || s2[init_s2] == '0')
        return (0);
    return (1);
}

int validate_left(t_game *game)
{
    int     i;
    int     init_s1;
    int     init_s2;
    char    *s1;
    char    *s2;

    i = 0;
    while (game->map.mtx[++i])
    {
        s1 = game->map.mtx[i - 1];
        s2 = game->map.mtx[i];
        init_s1 = find_init_line(s1);
        init_s2 = find_init_line(s2);
        if (!is_valid_at_pos(s1, s2, init_s1, init_s2))
            return (0);
        if (init_s1 < init_s2 && !is_valid_wall(s1, init_s1, init_s2))
            return (0);
        else if (init_s1 > init_s2 && !is_valid_wall(s2, init_s2, init_s1))
            return (0);
    }
    return (1);
}

int    validate_right(t_game *game)
{
    int     i;
    int     len_s1;
    int     len_s2;
    char    *s1;
    char    *s2;

    i = 0;
    while (game->map.mtx[++i])
    {
        s1 = game->map.mtx[i - 1];
        s2 = game->map.mtx[i];
        len_s1 = ft_strlen(s1);
        len_s2 = ft_strlen(s2);
        if (!is_valid_at_pos(s1, s2, len_s1 - 1, len_s2 - 1))
            return (0);
        if (len_s1 < len_s2 && !is_valid_wall(s2, len_s1, len_s2))
            return (0);
        else if (len_s1 > len_s2 && !is_valid_wall(s1, len_s2, len_s1))
            return (0);
    }
    return (1);
}
