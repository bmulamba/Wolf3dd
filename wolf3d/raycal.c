/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmulamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 06:47:48 by bmulamba          #+#    #+#             */
/*   Updated: 2018/08/16 08:43:35 by bmulamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		choose_dir(t_ray *ray, t_env *e)
{
	if (ray->ray_x < 0)
	{
		ray->step_x = -1;
		ray->dist_x = (e->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->dist_x = (ray->map_x + 1.0 - e->pos_x) * ray->delta_x;
	}
	if (ray->ray_y < 0)
	{
		ray->step_y = -1;
		ray->dist_y = (e->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->dist_y = (ray->map_y + 1.0 - e->pos_y) * ray->delta_y;
	}
}

static void		possible_move(t_env *e, t_ray *ray)
{
	int		stop;

	stop = 0;
	while (stop == 0)
	{
		if (ray->dist_x < ray->dist_y)
		{
			ray->dist_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->dist_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (e->map[ray->map_x][ray->map_y] != '0')
			stop = 1;
	}
}

float			ft_raycasting(t_env *e, t_ray *ray)
{
	ray->ray_x = e->dir_x + e->plan_x *
		(2 * e->x / (float)(W_H) - 1);
	ray->ray_y = e->dir_y + e->plan_y *
		(2 * e->x / (float)(W_H) - 1);
	ray->map_x = (int)(e->pos_x);
	ray->map_y = (int)(e->pos_y);
	ray->delta_x = sqrt(1 + pow(ray->ray_y, 2) / pow(ray->ray_x, 2));
	ray->delta_y = sqrt(1 + pow(ray->ray_x, 2) / pow(ray->ray_y, 2));
	choose_dir(ray, e);
	possible_move(e, ray);
	if (e->map[ray->map_x][ray->map_y] == '3')
		ray->side = 3;
	return ((ray->side == 0) ?
	fabs((ray->map_x - e->pos_x + (1 - ray->step_x) / 2) / ray->ray_x) :
	fabs((ray->map_y - e->pos_y + (1 - ray->step_y) / 2) / ray->ray_y));
}
