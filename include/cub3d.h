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
int     is_valid_down(char *line_down, int pos);
int     validate_down(t_game *game);
int     is_valid_up(char *line_up, int pos);
int     validate_left(t_game *game);
int     validate_right(t_game *game);










#endif

/*
Ter buraco na parede
Buraco no mapa (linha). Pode ter buraco se for do lado do 1.
Nao ter player, ou ter mais de 1.
Mapa vazio

11111
10101
11 11
1111


NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0


        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
*/