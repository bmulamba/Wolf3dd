/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmulamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 07:47:06 by bmulamba          #+#    #+#             */
/*   Updated: 2018/08/21 07:47:12 by bmulamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define W_H (800)
# define W_W (500)
# define BUF_SIZE 1

typedef struct	s_ray
{
	float		ray_x;
	float		ray_y;
	float		dist_x;
	float		dist_y;
	float		delta_x;
	float		delta_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
}				t_ray;

typedef struct	s_env
{
	float		speed;
	float		pos_x;
	float		pos_y;
	float		dir_x;
	float		dir_y;
	float		plan_x;
	float		plan_y;
	int			x;
	int			y;
	int			bpp;
	int			size_line;
	int			endian;
	void		*mlx;
	void		*img;
	void		*win;
	char		*data;
	char		**map;
	int			move_left;
	int			move_right;
	int			move_up;
	int			move_down;
	int			c1;
	int			c2;
	int			c3;
	t_ray		*ray;
}				t_env;

void			ft_parser(t_env *e);
void			ft_disp_wall(t_env *e);
void			rot(t_env *e, int move);
char			*read_file(const int fd);
void			move(t_env *e, int move);
int				key_hook(int keycode, t_env *e);
int				key_release(void);
float			ft_raycasting(t_env *e, t_ray *ray);
int				display(t_env *e);

#endif
