#include "../../include/cub3d.h"
/*
** Cut the new line at the end of the line
** Decide if the line is a texture or a color or a map.
** Call the right function to interpretate the line.
*/
void    interpretate_line(t_game *game, char *line_pre)
{
    char    *line2;
    char    *line;

    line2 = ft_strtrim(line_pre, "\n");
    line = ft_strtrim(line2, " ");
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
    free(line);
}

/*
** Open the file to read.
** Read the file line by line.
** If the line is not empty, interpretate it.
** At end, check if all information needed was given.
*/
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
        // When I already have a map, but appear some empty line inside or after it; --- Maybe check this in validate_map
        else if (game->map.mtx)
           exit_game("Incorect empty line or false information", game);
        free(line);
        line = get_nl(fd);
    }    
    if (!has_all_information(game))
        exit_game("Missing information", game);
    close(fd);
}