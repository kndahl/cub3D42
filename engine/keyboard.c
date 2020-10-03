/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:26:32 by kdahl             #+#    #+#             */
/*   Updated: 2020/09/25 17:40:46 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <time.h>

void	key_w(t_cub3d *cub3d)
{
	if (iswall(cub3d, 13))
		mouse(cub3d);
	else
	{
		cub3d->posx += cos(cub3d->posa) * 4;
		cub3d->posy += sin(cub3d->posa) * 4;
		cub3d->pressed = 1;
	}
}

void	key_d(t_cub3d *cub3d)
{
	if (iswall(cub3d, 5))
		mouse(cub3d);
	else
	{
		cub3d->posx -= cos(cub3d->posa - 1.57) * 3;
		cub3d->posy -= sin(cub3d->posa - 1.57) * 3;
		cub3d->pressed = 1;
	}
}

void	key_s(t_cub3d *cub3d)
{
	if (iswall(cub3d, 1))
		mouse(cub3d);
	else
	{
		cub3d->posx -= cos(cub3d->posa) * 2;
		cub3d->posy -= sin(cub3d->posa) * 2;
		cub3d->pressed = 1;
	}
}

void	key_a(t_cub3d *cub3d)
{
	if (iswall(cub3d, 5))
		mouse(cub3d);
	else
	{
		cub3d->posx += cos(cub3d->posa - 1.57) * 4;
		cub3d->posy += sin(cub3d->posa - 1.57) * 4;
		cub3d->pressed = 1;
	}
}

int		keyboard(int key, t_cub3d *cub3d)
{
	cub3d->pressed = 0;
	if (key == 53)
	{
		system("killall afplay");
		exit(0);
	}
	if (key == 13)
		key_w(cub3d);
	if (key == 2)
		key_d(cub3d);
	if (key == 1)
		key_s(cub3d);
	if (key == 0)
		key_a(cub3d);
	if (key == 12)
		sounds_setting(cub3d);
	return (0);
}
