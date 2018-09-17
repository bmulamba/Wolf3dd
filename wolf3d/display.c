/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmulamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 06:45:20 by bmulamba          #+#    #+#             */
/*   Updated: 2018/08/16 15:50:17 by bmulamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				pixel_put(t_env *e, char *data)
{
	if (!e->bpp || !e->size_line)
		exit(EXIT_FAILURE);
	data[(e->x * e->bpp / 8) +
		(e->y * e->size_line)] = e->c1;
	data[(e->x * e->bpp / 8) +
		(e->y * e->size_line) + 1] = e->c2;
	data[(e->x * e->bpp / 8) +
		(e->y * e->size_line) + 2] = e->c3;
	return (0);
}

int				expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void			ft_color(t_env *e, t_ray *ray, int w, float y)
{
	if (y > -w / 2 + W_W / 2 && y < w / 2 + W_W / 2 - 1 && ray->side == 0)
	{
		e->c1 = 0;
		e->c2 = 0;
		e->c3 = 255;
	}
	else if (y > -w / 2 + W_W / 2 && y < w / 2 + W_W / 2 - 1 && ray->side == 1)
	{
		e->c1 = 255;
		e->c2 = 255;
		e->c3 = 0;
	}
	else if (y > -w / 2 + W_W / 2 && y < w / 2 + W_W / 2 - 1 && ray->side == 3)
	{
		e->c1 = 255;
		e->c2 = 128;
		e->c3 = 128;
	}
	else
	{
		e->c1 = 255;
		e->c2 = 140 + y / 2;
		e->c3 = 40;
	}
}

void			ft_disp_wall(t_env *e)
{
	float	wall;

	e->x = -1;
	while (++e->x < W_H)
	{
		e->y = -1;
		wall = ft_raycasting(e, e->ray);
		while (++e->y < W_W)
		{
			ft_color(e, e->ray, abs((int)(W_W / wall)), e->y);
			pixel_put(e, e->data);
		}
	}
}

int				display(t_env *e)
{
	ft_disp_wall(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_expose_hook(e->win, &expose_hook, e);
	return (0);
}
