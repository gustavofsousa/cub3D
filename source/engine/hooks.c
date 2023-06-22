#include "../../include/cub3d.h"

void	walk_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.x + data->player.dirX * data->player.speed;
	new_y = data->player.y + data->player.dirY * data->player.speed;
	if (data->map[(int)trunc(new_x)][(int)trunc(data->player.y)] == 0)
		data->player.x = new_x;
	if (data->map[(int)trunc(data->player.x)][(int)trunc(new_y)] == 0)
		data->player.y = new_y;
}

void	walk_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.x - data->player.dirX * data->player.speed;
	new_y = data->player.y - data->player.dirY * data->player.speed;
	if (data->map[(int)trunc(new_x)][(int)trunc(data->player.y)] == 0)
		data->player.x = new_x;
	if (data->map[(int)trunc(data->player.x)][(int)trunc(new_y)] == 0)
		data->player.y = new_y;
}

void	walk_left(t_player *player)
{
	double	old_x;

	old_x = (player->dirX);
	player->dirX = player->dirX * cos(-player->rot_speed)
		- player->dirY * sin(-player->rot_speed);
	player->dirY = old_x * sin(-player->rot_speed)
		+ player->dirY * cos(-player->rot_speed);
	old_x = player->cam_plane_dirX;
	player->cam_plane_dirX = player->cam_plane_dirX * cos(-player->rot_speed)
		- player->cam_plane_dirY * sin(-player->rot_speed);
	player->cam_plane_dirY = old_x * sin(-player->rot_speed)
		+ player->cam_plane_dirY * cos(-player->rot_speed);
}

void	walk_right(t_player *player)
{
	double	old_x;

	old_x = (player->dirX);
	player->dirX = player->dirX * cos(player->rot_speed)
		- player->dirY * sin(player->rot_speed);
	player->dirY = old_x * sin(player->rot_speed)
		+ player->dirY * cos(player->rot_speed);
	old_x = player->cam_plane_dirX;
	player->cam_plane_dirX = player->cam_plane_dirX * cos(player->rot_speed)
		- player->cam_plane_dirY * sin(player->rot_speed);
	player->cam_plane_dirY = old_x * sin(player->rot_speed)
		+ player->cam_plane_dirY * cos(player->rot_speed);
}

int	close_window(t_data *data)
{
	if (data->img.mlx_win)
		mlx_destroy_window(data->img.mlx, data->img.mlx_win);
	exit(0);
}
