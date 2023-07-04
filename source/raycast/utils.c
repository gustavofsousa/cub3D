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

int	looking_north(t_ray_info *ray)
{
	return (ray->dir.y < 0);
}

int	looking_south(t_ray_info *ray)
{
	return (ray->dir.y > 0);
}

int	looking_east(t_ray_info *ray)
{
	return (ray->dir.x > 0);
}

int	looking_west(t_ray_info *ray)
{
	return (ray->dir.x < 0);
}
