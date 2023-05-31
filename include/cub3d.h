#ifndef CUB3D_H
#define CUB3D_H

# include "../libft/libft.h"
# include "structs.h"
# include "constants.h"
# include "../mlx_linux/mlx.h"
//# include "../miniLibX/mlx.h"
# include <fcntl.h> //open().
# include <stdio.h> //printf

void    setup(t_game *game);
void    render_game(t_game *game);
void	exit_game(char *message, t_game *game);

// interpretate_map
void    interpretate_map(t_game *game, char *path_name);
int     has_all_information(t_game *game);
int     open_file(char *file_path);

//Texture
int     is_xpm(char *line);
int     get_texture(t_game *game, char *line);
int     is_north(char *cardinal, t_game *game);
int     is_south(char *cardinal, t_game *game);
int     is_west(char *cardinal, t_game *game);
int     is_east(char *cardinal, t_game *game);

// Color
int     is_color(char *line);
void    get_color(t_game *game, char *line);
int     is_ceiling(char *cardinal, t_game *game);
int     is_floor(char *cardinal, t_game *game);

// Common libft
void    free_matrix(char **matrix);
void    update_matrix(char ***matrix, char *new_line);
int     ft_count_words(char const *s, char c);
int     is_empty_line(char *line);
int     is_space(char c);


// Validate_map
void    validate_map(t_game *game);
void    validate_player(t_game *game);
void    validate_border(t_game *game);
void    validate_char(t_game *game);
int     validate_up(t_game *game);
int     validate_down(t_game *game);
int     validate_left(t_game *game);
int     validate_right(t_game *game);






#endif