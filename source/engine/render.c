#include "../../include/cub3d.h"

unsigned long	tex_color(t_game *game, t_img tex, int tex_pos, int tex_hit_x)
{
	int	tex_y;
	int	*texture;

	texture = (int *) tex.addr;
	tex_y = (int)tex_pos & (tex.height - 1);
	return (texture[tex.height * tex_y + tex_hit_x]);
}

t_img	def_tex(t_game *game, t_ray_info *ray)
{
	if (ray->side_hit)
	{
		if (ray->dir.y < 0)
			return (game->texture.north);
		return (game->texture.south);
	}
	else
	{
		if (ray->dir.x > 0)
			return (game->texture.east);
		return (game->texture.west);
	}
}

void	raycast(t_game *game)
{
	int			x;
	int			line_height;
	t_ray_info	ray;

	x = 0;
	while (x < LENGHT)
	{
		ray.dir = calc_ray_dir(x, game);
		calc_perp_wall_dist(game, &ray);
		line_height = (int)(HEIGHT / ray.perp_wall_dist);
		draw_x_line(game, &ray, line_height, x);
		x++;
	}
}