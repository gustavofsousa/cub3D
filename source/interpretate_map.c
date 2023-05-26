#include "../include/cub3d.h"

void    interpretate_line(t_game *game, char *line)
{
    trim_new_line(&line);
    if (get_texture(game, line))
        return ;
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

    // Function for the open();
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