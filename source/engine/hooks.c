#include "../../include/cub3d.h"

void walk_forward(t_data *data)
{
  double new_x;
  double new_y;

  new_x = data->player.play_x + data->player.dirX * data->player.speed;
  new_y = data->player.play_y + data->player.dirY * data->player.speed;
  if (data->map[(int)trunc(new_x)][(int)trunc(data->player.play_y)] == 0)
    data->player.play_x = new_x;
  if (data->map[(int)trunc(data->player.play_x)][(int)trunc(new_y)] == 0)
    data->player.play_y = new_y;
}

void walk_backward(t_data *data)
{
  double new_x;
  double new_y;

  new_x = data->player.play_x - data->player.dirX * data->player.speed;
  new_y = data->player.play_y - data->player.dirY * data->player.speed;
  if (data->map[(int)trunc(new_x)][(int)trunc(data->player.play_y)] == 0)
    data->player.play_x = new_x;
  if (data->map[(int)trunc(data->player.play_x)][(int)trunc(new_y)] == 0)
    data->player.play_y = new_y;
}

void walk_left(t_data *data)
{
  double oldX;

  oldX = (data->player.dirX);
  data->player.dirX = data->player.dirX * cos(-data->player.rot_speed) - data->player.dirY * sin(-data->player.rot_speed);
  data->player.dirY = oldX * sin(-data->player.rot_speed) + data->player.dirY * cos(-data->player.rot_speed);
  oldX = data->player.cam_plane_dirX;
  data->player.cam_plane_dirX = data->player.cam_plane_dirX * cos(-data->player.rot_speed) - data->player.cam_plane_dirY * sin(-data->player.rot_speed);
  data->player.cam_plane_dirY = oldX * sin(-data->player.rot_speed) + data->player.cam_plane_dirY * cos(-data->player.rot_speed);
}

void walk_right(t_data *data)
{
  double oldX;

  oldX = (data->player.dirX);
  data->player.dirX = data->player.dirX * cos(data->player.rot_speed) - data->player.dirY * sin(data->player.rot_speed);
  data->player.dirY = oldX * sin(data->player.rot_speed) + data->player.dirY * cos(data->player.rot_speed);
  oldX = data->player.cam_plane_dirX;
  data->player.cam_plane_dirX = data->player.cam_plane_dirX * cos(data->player.rot_speed) - data->player.cam_plane_dirY * sin(data->player.rot_speed);
  data->player.cam_plane_dirY = oldX * sin(data->player.rot_speed) + data->player.cam_plane_dirY * cos(data->player.rot_speed);
}

int close_window(t_data *data)
{
	if (data->img.mlx_win)
		mlx_destroy_window(data->img.mlx, data->img.mlx_win);
	exit(0);
}