#include "../../include/cub3d.h"

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