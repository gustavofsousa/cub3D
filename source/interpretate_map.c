#include "../include/cub3d.h"

char    *get_path_texture(char *line)
{
    char    **line_mtx;
    char    *path_text;
    int     i;

    line_mtx  = ft_split(line, ' ');
    path_text = ft_strdup(line_mtx[1]);
    i = -1;
    while (line_mtx[++i])
        free(line_mtx[i]);
    free(line_mtx);
    return (path_text);
}

/*
*   Fazer nao ficar voltando, nem olhar de forma tao bruta, mais clean.
*/
void    interpretate_line(t_game *game, char *line, int count)
{
    if (!ft_strncmp("NO", line, 2) && !game->texture.north)
        game->texture.north = get_path_texture(line);
    else if (!ft_strncmp("SO", line, 2) && !game->texture.south)
        game->texture.south = get_path_texture(line);
    else if (!ft_strncmp("WE", line, 2) && !game->texture.west)
        game->texture.west = get_path_texture(line);
    else if (!ft_strncmp("EA", line, 2) && !game->texture.east)
        game->texture.east = get_path_texture(line);
    else
    {
        game->map.mtx[count] = ft_strdup(line);
        // game->map.width = max(atual or strlen(line));
    }
}

// Leio a linha
// E guardo ou na textura ou na matrix.
void    interpretate_map(t_game *game, char *file_path)
{
    int     i;
    char    *line;
    int     fd;

    i = 0;
    fd = open(file_path, O_RDONLY);
    line = get_nl(fd);
    while (line)
    {
        if (line[0] != '\n')
        {
            interpretate_line(game, line, i);
            i++;
        }
        // When I already have a map, but appear some empty line inside it;
       // else if (game->map.mtx)
       //     exit_app(game);
        free(line);
        line = get_nl(fd);
    }
    game->map.mtx[i] = NULL;
    game->map.height = i;
    close(fd);
}