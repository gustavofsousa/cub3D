#include "../../include/cub3d.h"

void	walk_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.dirX * game->player.speed;
	new_y = game->player.y + game->player.dirY * game->player.speed;
	if (game->map.mtx[(int)trunc(new_x)][(int)trunc(game->player.y)] == 0)
		game->player.x = new_x;
	if (game->map.mtx[(int)trunc(game->player.x)][(int)trunc(new_y)] == 0)
		game->player.y = new_y;
}

void	walk_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x - game->player.dirX * game->player.speed;
	new_y = game->player.y - game->player.dirY * game->player.speed;
	if (game->map.mtx[(int)trunc(new_x)][(int)trunc(game->player.y)] == 0)
		game->player.x = new_x;
	if (game->map.mtx[(int)trunc(game->player.x)][(int)trunc(new_y)] == 0)
		game->player.y = new_y;
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

int	close_window(t_game *game)
{
	if (game->img.win)
		mlx_destroy_window(game->img.ptr, game->img.win);
	exit(0);
}
