#include "../include/cub3d.h"

// make img to texture
t_img   get_path_texture(char *path, t_game *game)
{
    t_img   texture;

    texture.ptr = mlx_init();
    texture.img = mlx_xpm_file_to_image(texture.ptr, path, &texture.width, &texture.height);
    if (!texture.img)
        exit_game("Invalid texture path", game);
    texture.addr = (int *)mlx_get_data_addr(texture.img, &texture.bpp, &texture.line_len, &texture.endian);
    //texture.line_len /= 4;
    return (texture);
}

// Functions for the strncmp
int get_texture(t_game *game, char *line)
{
    char    *cardinal;
    char    **line_mtx;
    char    *path_text;

    if (ft_count_words(line, ' ') != 2)
        exit_game("Incorrect number of information", game);
    line_mtx  = ft_split(line, ' ');
    cardinal = line_mtx[0];
    path_text = line_mtx[1];
    if (!ft_strncmp("NO", cardinal, 3) && !game->texture.north.ptr)
        game->texture.north = get_path_texture(path_text, game);
    else if (!ft_strncmp("SO", cardinal, 3) && !game->texture.south.ptr)
        game->texture.south = get_path_texture(path_text, game );
    else if (!ft_strncmp("WE", cardinal, 3) && !game->texture.west.ptr)
        game->texture.west = get_path_texture(path_text, game);
    else if (!ft_strncmp("EA", cardinal, 3) && !game->texture.east.ptr)
        game->texture.east = get_path_texture(path_text, game);
    else if (!ft_strncmp("C", cardinal, 2) && game->texture.ceiling == -1)
        game->texture.ceiling = get_color(path_text, game);
    else if (!ft_strncmp("F", cardinal, 2) && game->texture.floor == -1)
        game->texture.floor = get_color(path_text, game);
    else
    {
        free_matrix(line_mtx);
        return (0);
    }
    free_matrix(line_mtx);
    return (1);
}

int is_xpm(char *line)
{
    while (*line && *line != '.')
        line++;
    if (!ft_strncmp(line, ".xpm", 4) && *(line + 4) == '\0')
        return (1);
    return (0);
}