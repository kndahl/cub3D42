/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:23:24 by kdahl             #+#    #+#             */
/*   Updated: 2020/09/11 20:27:57 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static float	longrays(float c, t_cub3d *cub3d)
{
	float	x;
	float	y;
	float	wx;
	float	wy;

	while (1)
	{
		c += 1;
		x = cub3d->posx + c * cos(cub3d->raya);
		y = cub3d->posy + c * sin(cub3d->raya);
		modff(x / cub3d->cell_x_len, &wx);
		modff(y / cub3d->cell_y_len, &wy);
		if (cub3d->worldmap[(int)wy][(int)wx] == 1)
		{
			c -= 0.99;
			break ;
		}
	}
	return (c);
}

static void		checkwallside(t_cub3d *cub3d)
{
	if (fabs(cub3d->hity) > fabs(cub3d->hitx))
	{
		if (sin(cub3d->raya) < 0)
			cub3d->side = 2;
		else
			cub3d->side = 1;
		cub3d->x_texcoord = (cub3d->hitx / cub3d->cell_y_len) * cub3d->t_width;
	}
	else
	{
		if (cos(cub3d->raya) < 0)
			cub3d->side = 3;
	}
	if (cub3d->x_texcoord < 0)
		cub3d->x_texcoord += cub3d->t_width;
}

static void		calculations(float x, float y, t_cub3d *cub3d)
{
	float	no_use;

	cub3d->hx = x;
	cub3d->hy = y;
	cub3d->hitx = (float)(cub3d->cell_x_len >> 1)
	- (modff(cub3d->hx / cub3d->cell_x_len, &no_use)
	* cub3d->cell_x_len);
	cub3d->hity = (float)(cub3d->cell_y_len >> 1)
	- (modff(cub3d->hy / cub3d->cell_y_len, &no_use)
	* cub3d->cell_y_len);
	cub3d->x_texcoord = (cub3d->hity / cub3d->cell_x_len)
	* cub3d->t_width;
}

static float	shortrays(float c, t_cub3d *cub3d)
{
	float	x;
	float	y;
	float	wx;
	float	wy;

	while (1)
	{
		c += .009;
		cub3d->side = 0;
		x = cub3d->posx + c * cos(cub3d->raya);
		y = cub3d->posy + c * sin(cub3d->raya);
		modff(x / cub3d->cell_x_len, &wx);
		modff(y / cub3d->cell_y_len, &wy);
		if (cub3d->worldmap[(int)wy][(int)wx] == 1)
		{
			calculations(x, y, cub3d);
			checkwallside(cub3d);
			break ;
		}
	}
	return (c);
}

void			drawrays3d(t_cub3d *cub3d)
{
	float		raydist;
	float		fov;
	float		c;
	int			r;

	r = 0;
	fov = M_PI / 3;
	raydist = 10000;
	while (r < cub3d->screenwidth)
	{
		cub3d->raya = cub3d->posa - fov / 2 + fov * r / cub3d->screenwidth;
		c = 0;
		c = longrays(c, cub3d);
		c = shortrays(c, cub3d);
		raydist = dist(cub3d->posx, cub3d->posy, cub3d->hx, cub3d->hy);
		draw3dscene(raydist, r, cub3d);
		r++;
	}
}
