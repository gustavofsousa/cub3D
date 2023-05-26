#include "../include/cub3d.h"


char    *get_path_texture(char *line, t_game *game)
{
    char    **line_mtx;
    char    *path_text;
    char    *trimmed;

    trimmed = ft_strtrim(line, "\n");
    if (ft_count_words(trimmed, ' ') != 2)
        exit_game("Incorrect number of information", game);
    line_mtx  = ft_split(trimmed, ' ');
    path_text = ft_strdup(line_mtx[1]);
    free_matrix(line_mtx);
    free (trimmed);
    return (path_text);
}



/*
*   Fazer nao ficar voltando, nem olhar de forma tao bruta, mais clean.
*   Itś possible to texture turn into an array and I acces it with an enum north, south, west, east.
*/
void    interpretate_line(t_game *game, char *line)
{
    if (!ft_strncmp("NO", line, 2) && !game->texture.north)
        game->texture.north = get_path_texture(line, game);
    else if (!ft_strncmp("SO", line, 2) && !game->texture.south)
        game->texture.south = get_path_texture(line, game );
    else if (!ft_strncmp("WE", line, 2) && !game->texture.west)
        game->texture.west = get_path_texture(line, game);
    else if (!ft_strncmp("EA", line, 2) && !game->texture.east)
        game->texture.east = get_path_texture(line, game);
    else
    {
        update_matrix(&game->map.mtx, line);
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

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        exit_game("File non-existed or non-permission granted", game);
    line = get_nl(fd);
    i = 0;
    while (line)
    {

        if (line[0] != '\n' && i++)//empty line()
            interpretate_line(game, line);
        // When I already have a map, but appear some empty line inside or after it;
        else if (game->map.mtx)//exit_map();
           exit_game("Incorect empty line or false information", game);
        free(line);
        line = get_nl(fd);
    }
    if (game->map.mtx == NULL)
        exit_game("Map non-existed", game);
    else
        game->map.mtx[i] = NULL;
    game->map.height = i;
    close(fd);
}