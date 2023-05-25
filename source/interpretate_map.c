#include "../include/cub3d.h"

int is_not_valid_map(char **map. int i)
{
    if (map[0] ==)
}

void    interpretate_line(t_game *game, char *line)
{
    if (!ft_strncmp(("NO", line[0 e 1])))

}

void    interpretate_map(t_game *game)
{
    int     i;
    char    *line;

    i = 0;
    open(file_path);
    while (42)
    {
        line = get_nl(file_path);
        interpretate_line(game, line);
        if (is_not_valid_map(game->map.mtx))
            exit_app(game);
        if (game->map.mtx[i] == NULL)
            break;
        game->map.height++;
    }
}