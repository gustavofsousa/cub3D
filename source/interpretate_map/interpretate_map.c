#include "../../include/cub3d.h"

void    interpretate_line(t_game *game, char *line)
{
    trim_new_line(&line);
    if (is_xpm(line))
        get_texture(game, line);
    else if (is_color(line))
        get_color(game, line);
    else
    {
        update_matrix(&game->map.mtx, line);
        game->map.height++;
        //game->map.width = max(atual or strlen(line));
    }
}

int has_all_information(t_game *game)
{
    if (game->map.mtx == NULL)
        return (0);
    game->map.mtx[game->map.height] = NULL;
    if (!game->texture.north.ptr
        || !game->texture.south.ptr
        || !game->texture.west.ptr
        || !game->texture.east.ptr
        || game->texture.ceiling == -1
        || game->texture.floor == -1)
        return (0);
    return (1);
}

int open_file(char *file_path)
{
    int fd;

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        exit_game("File non-existed or non-permission granted", NULL);
    return (fd);
}

// Leio a linha
// E guardo ou na textura ou na matrix.
void    interpretate_map(t_game *game, char *file_path)
{
    char    *line;
    int     fd;

    fd = open_file(file_path);
    line = get_nl(fd);
    while (line)
    {
        if (!is_empty_line(line))
            interpretate_line(game, line);
        // When I already have a map, but appear some empty line inside or after it;
        else if (game->map.mtx)//exit_map();
           exit_game("Incorect empty line or false information", game);
        free(line);
        line = get_nl(fd);
    }    
    if (!has_all_information(game))
        exit_game("Missing information", game);
    close(fd);
}