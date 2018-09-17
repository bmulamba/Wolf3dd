/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmulamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 06:23:45 by bmulamba          #+#    #+#             */
/*   Updated: 2018/08/31 07:39:09 by bmulamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 124 || keycode == 123)
		(keycode == 124) ? rot(e, 1) : rot(e, -1);
	if (keycode == 126 || keycode == 125)
		(keycode == 126) ? move(e, 1) : move(e, -1);
	if (keycode == 53 && write(1, "\e\x1b[31mEnd of Program!\n", 25))
		exit(EXIT_FAILURE);
	return (0);
}

int		key_release(void)
{
	write(1, "\e\x1b[31End of Program!\n", 25);
	exit(EXIT_FAILURE);
	return (0);
}
