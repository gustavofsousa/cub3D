#include "../include/cub3d.h"

int translate_rgb(char *rgb, t_game *game)
{
    (void)game;
    (void)rgb;
    return (1);
}

void get_color(t_game *game, char *line)
{
    char    *cardinal;
    char    **line_mtx;
    char    *arg;

    line_mtx  = ft_split(line, ' ');
    cardinal = line_mtx[0];
    arg = line_mtx[1];
    if (is_ceiling(cardinal, game))
        game->texture.ceiling = translate_rgb(arg, game);
    else if (is_floor(cardinal, game))
        game->texture.floor = translate_rgb(arg, game);
}

int is_color(char *line)
{
    if (ft_count_words(line, ',') != 3)
        return (0);
    return (1);
}