/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:12:10 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/07/05 15:04:09 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../libft/libft.h"
# include "structs.h"
# include "constants.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h> //open().
# include <stdio.h> //printf
# include <math.h>

void			setup(t_game *game);
void			render_game(t_game *game);
void			exit_game(char *message, t_game *game);
int				close_window(t_game *game);

// interpretate_map
void			interpretate_map(t_game *game, char *path_name);
int				has_all_information(t_game *game);
int				open_file(char *file_path);

// Texture
int				is_xpm(char *line);
int				get_texture(t_game *game, char *line);
int				is_north(char *cardinal, t_game *game);
int				is_south(char *cardinal, t_game *game);
int				is_west(char *cardinal, t_game *game);
int				is_east(char *cardinal, t_game *game);

// Color
int				is_color(char *line);
void			get_color(t_game *game, char *line);
int				is_ceiling(char *cardinal, t_game *game);
int				is_floor(char *cardinal, t_game *game);

// Common libft
void			free_matrix_int(t_game *game);
void			update_matrix(char ***matrix, char *new_line);
int				ft_count_words(char const *s, char c);

// Validate_map
void			validate_map(t_game *game);
void			validate_player(t_game *game);
void			validate_char(t_game *game);
void			validate_border(t_game *game);
int				validate_up(t_game *game);
int				validate_down(t_game *game);
int				validate_left(t_game *game);
int				validate_right(t_game *game);
void			validate_middle(t_game *game);
int				is_valid_up_down(char *line_updown, int pos);

// Transform_map
void			transform_map_int(t_game *game);
void			transpose_matrix(t_game *game);

// Minimap
void			draw_map2d(t_game *game, int square_sz);
void			draw_miniplayer(t_img *img, t_player player, int l);
void			bresenham_x(t_img *img, int i[2], int f[2], int color);
void			bresenham_y(t_img *img, int i[2], int f[2], int color);

// Movement
void			walk_forward(t_player *player, t_map *map);
void			walk_backward(t_player *player, t_map *map);
void			walk_right(t_player *player, t_map *map);
void			walk_left(t_player *player, t_map *map);
void			turn_right(t_player *player);
void			turn_left(t_player *player);

// Ray casting
void			paint_walls(t_game *game);
void			draw_background(t_game game);
int				looking_north(t_ray_info *ray);
int				looking_south(t_ray_info *ray);
int				looking_west(t_ray_info *ray);
int				looking_east(t_ray_info *ray);
void			config_step(t_ray_info *ray);

// Draw
void			pixel_put(t_img *data, int x, int y, int color);

// ray config
void			config_ray(t_game *game, t_ray_info *ray, int actual_ray);
int				vertical_wall(t_ray_info *ray);
int				horizontal_wall(t_ray_info *ray);

// Texture configs
t_img			choose_texture(t_game *game, t_ray_info *ray);
int				get_scale_y(t_game *game, t_ray_info *ray, t_img tex);
double			get_scale_x(int begin, int line_height, double step_tex);
unsigned long	tex_color(t_img tex, int tex_pos, int tex_hit_x);

// Hoooks key
void			create_window_mlx(t_game *game);
void			prepare_hooks_keys(t_game *game);

// Utils
void			print_mtx(t_game *game);

#endif
