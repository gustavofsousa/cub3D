#include "../include/cub3d.h"

int handle_key_press(int keycode, t_data *data)
{
    if (keycode == 65362 || keycode == 119) // Replace KEY_W with the key you want to use for walking
		data->key.w_is_press = 1;// Additional code for player movement
	if (keycode == 65364 || keycode == 115)
		data->key.s_is_press = 1;
	if (keycode == 65363 || keycode == 100)
		data->key.d_is_press = 1;
	if (keycode == 65361 || keycode == 97)
		data->key.a_is_press = 1;
    return (0);
}

int handle_key_release(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->img.mlx, data->img.mlx_win);
		exit(0);
	}
	if (keycode == 65362 || keycode == 119) // Replace KEY_S with the key you want to use for walking
		data->key.w_is_press = 0;
	if (keycode == 65364 || keycode == 115) // Replace KEY_S with the key you want to use for walking
		data->key.s_is_press = 0;
	if (keycode == 65363 || keycode == 100)
		data->key.d_is_press = 0;
	if (keycode == 65361 || keycode == 97)
		data->key.a_is_press = 0;
	return (0);
}

int loop_hook(t_data *data)
{
	if (data->key.w_is_press || data->key.s_is_press || data->key.d_is_press || data->key.a_is_press)
		render_map3d(data);
	if (data->key.w_is_press)
		walk_forward (data);
	if (data->key.s_is_press)
		walk_backward (data);
	if (data->key.d_is_press)
		walk_right (data);
	if (data->key.a_is_press)
		walk_left (data);
	// render_map2d(data, 22);
	render_player(&data->img, data->player, 12);
	mlx_put_image_to_window(data->img.mlx, data->img.mlx_win, data->img.img, 0,
			0);
	return (0);
}

void	render_game(t_data *data)
{
	render_player(&data->img, data->player, 12);
	mlx_hook(data->img.mlx_win, 2, 1L << 0, handle_key_press, data);
	mlx_hook(data->img.mlx_win, 3, 1L << 1, handle_key_release, data);
	mlx_loop_hook(data->img.mlx, loop_hook, data);
	mlx_put_image_to_window(data->img.mlx, data->img.mlx_win, data->img.img, 0, 0);
	mlx_loop(data->img.mlx);
}