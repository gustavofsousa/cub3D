/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/04 17:01:08 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	horizontal_wall(t_ray_info *ray)
{
	return (ray->side_hit == 0);
}

int	vertical_wall(t_ray_info *ray)
{
	return (ray->side_hit == 1);
}

void	config_step(t_ray_info *ray)
{
	ray->step.x = fabs(1.0 / ray->dir.x);
	ray->step.y = fabs(1.0 / ray->dir.y);
}
