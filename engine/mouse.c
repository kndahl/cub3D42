/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 19:07:45 by kdahl             #+#    #+#             */
/*   Updated: 2020/09/10 19:51:48 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		go_straight(t_cub3d *cub3d)
{
	if (cub3d->worldmap[(int)(((float)cub3d->mapheight /
	(cub3d->cell_y_len * cub3d->mapheight))
	* (cub3d->posy + 5 + (sin(cub3d->posa) * 5)))]
	[(int)(((float)cub3d->mapwidth / (cub3d->cell_x_len * cub3d->mapwidth))
	* (cub3d->posx + (cos(cub3d->posa) * 5)))] == 1)
		return (1);
	if (cub3d->worldmap[(int)(((float)cub3d->mapheight /
	(cub3d->cell_y_len * cub3d->mapheight))
	* (cub3d->posy + 5 - (sin(cub3d->posa) * 5)))]
	[(int)(((float)cub3d->mapwidth / (cub3d->cell_x_len * cub3d->mapwidth))
	* (cub3d->posx - (cos(cub3d->posa) * 5)))] == 1)
		return (1);
	return (0);
}

int		go_back(t_cub3d *cub3d)
{
	if (cub3d->worldmap[(int)(((float)cub3d->mapheight /
	(cub3d->cell_y_len * cub3d->mapheight))
	* (cub3d->posy - 5 + (sin(cub3d->posa) * 5)))]
	[(int)(((float)cub3d->mapwidth / (cub3d->cell_x_len * cub3d->mapwidth))
	* (cub3d->posx + (cos(cub3d->posa) * 5)))] == 1)
		return (1);
	if (cub3d->worldmap[(int)(((float)cub3d->mapheight /
	(cub3d->cell_y_len * cub3d->mapheight))
	* (cub3d->posy - 5 - (sin(cub3d->posa) * 5)))]
	[(int)(((float)cub3d->mapwidth / (cub3d->cell_x_len * cub3d->mapwidth))
	* (cub3d->posx - (cos(cub3d->posa) * 5)))] == 1)
		return (1);
	return (0);
}

int		go_leftright(t_cub3d *cub3d)
{
	if (cub3d->worldmap[(int)(((float)cub3d->mapheight /
	(cub3d->cell_y_len * cub3d->mapheight))
	* (cub3d->posy + (sin(cub3d->posa) * 5)))]
	[(int)(((float)cub3d->mapwidth / (cub3d->cell_x_len * cub3d->mapwidth))
	* (cub3d->posx + 5 + (cos(cub3d->posa) * 5)))] == 1)
		return (1);
	if (cub3d->worldmap[(int)(((float)cub3d->mapheight /
	(cub3d->cell_y_len * cub3d->mapheight))
	* (cub3d->posy + (sin(cub3d->posa) * 5)))]
	[(int)(((float)cub3d->mapwidth / (cub3d->cell_x_len * cub3d->mapwidth))
	* (cub3d->posx - 5 + (cos(cub3d->posa) * 5)))] == 1)
		return (1);
	return (0);
}

void	rotate(t_cub3d *cub3d)
{
	if (cub3d->delta_w < 0)
	{
		cub3d->posa -= (0.10471975512 / 16 * fabs(cub3d->delta_w));
		if (cub3d->posa < 0)
			cub3d->posa += 2 * M_PI;
		cub3d->dirx = cos(cub3d->posa) * fabs(cub3d->delta_w);
		cub3d->diry = sin(cub3d->posa) * fabs(cub3d->delta_w);
		cub3d->pressed = 1;
	}
	else
	{
		cub3d->posa += (0.10471975512 / 16 * cub3d->delta_w);
		if (cub3d->posa > 2 * M_PI)
			cub3d->posa -= 2 * M_PI;
		cub3d->dirx = cos(cub3d->posa) * cub3d->delta_w;
		cub3d->diry = sin(cub3d->posa) * cub3d->delta_w;
		cub3d->pressed = 1;
	}
}

void	mouse(t_cub3d *cub3d)
{
	mlx_mouse_get_pos(cub3d->window_ptr, &cub3d->posx_w, &cub3d->posy_w);
	if (cub3d->mouse_on)
	{
		cub3d->delta_w = cub3d->posx_w - (cub3d->screenwidth / 2);
		if (cub3d->delta_w != 0)
			rotate(cub3d);
		mlx_mouse_hide();
		mlx_mouse_move(cub3d->window_ptr, cub3d->screenwidth / 2,
		cub3d->screenheight / 2);
	}
	else
		return ;
}
