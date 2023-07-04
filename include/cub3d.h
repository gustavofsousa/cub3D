#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "structs.h"
# include "constants.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h> //open().
# include <stdio.h> //printf
# include <math.h>

void	setup(t_game *game);
void	render_game(t_game *game);
void	exit_game(char *message, t_game *game);
int		close_window(t_game *game);

// interpretate_map
void	interpretate_map(t_game *game, char *path_name);
int		has_all_information(t_game *game);
int		open_file(char *file_path);

//Texture
int		is_xpm(char *line);
int		get_texture(t_game *game, char *line);
int		is_north(char *cardinal, t_game *game);
int		is_south(char *cardinal, t_game *game);
int		is_west(char *cardinal, t_game *game);
int		is_east(char *cardinal, t_game *game);

// Color
int		is_color(char *line);
void	get_color(t_game *game, char *line);
int		is_ceiling(char *cardinal, t_game *game);
int		is_floor(char *cardinal, t_game *game);

// Common libft
void	free_matrix(char **matrix);
void	free_matrix_int(t_game *game);
void	update_matrix(char ***matrix, char *new_line);
int		ft_count_words(char const *s, char c);
int		is_empty_line(char *line);
int		is_space(char c);
void    ft_swap(int *a, int *b);

// Validate_map
void	validate_map(t_game *game);
void	validate_player(t_game *game);
void	validate_char(t_game *game);
void	validate_border(t_game *game);
int		validate_up(t_game *game);
int		validate_down(t_game *game);
int		validate_left(t_game *game);
int		validate_right(t_game *game);
void	validate_middle(t_game *game);
int		is_valid_up_down(char *line_updown, int pos);

// Transform_map
void	transform_map_int(t_game *game);
void    transpose_matrix(t_game *game);

// Minimap
void	draw_map2d(t_game *game, int square_sz);
void	draw_miniplayer(t_img *img, t_player player, int l);
void	bresenham_x(t_img *img, int i[2], int f[2], int color);
void	bresenham_y(t_img *img, int i[2], int f[2], int color);

// Movement
void	walk_forward(t_player *player, t_map *map);
void	walk_backward(t_player *player, t_map *map);
void	walk_right(t_player *player, t_map *map);
void	walk_left(t_player *player, t_map *map);
void	turn_right(t_player *player);
void	turn_left(t_player *player);

// Ray casting
void	paint_walls(t_game *game);
void	draw_background(t_game game);
void	draw_x_line(t_game *game, t_ray_info *ray, int line_height, int x);
int     looking_north(t_ray_info *ray);
int     looking_south(t_ray_info *ray);
int     looking_west(t_ray_info *ray);
int     looking_east(t_ray_info *ray);


// Draw
void	pixel_put(t_img *data, int x, int y, int color);

// Calculations
t_double_vector	calc_ray_dir(int x, t_player *player);
void	calc_perp_wall_dist(t_game *game, t_ray_info *ray);
int     calc_lowest_pixel(int line_height);
int     calc_highest_pixel(int line_height);
double	calc_tile_hit_x(t_game *game, t_ray_info *ray);
int		calc_tex_hit_x(t_game *game, t_ray_info *ray, t_img tex);
unsigned long	tex_color(t_img tex, int tex_pos, int tex_hit_x);
t_img	def_tex(t_game *game, t_ray_info *ray);

// Hoooks key
void	prepare_hooks_keys(t_game *game);


// Utils
void	print_mtx(t_game *game);

#endif
