/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:21:25 by kdahl             #+#    #+#             */
/*   Updated: 2020/09/25 17:30:52 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw3dsky(float lineh, float lineo, int r, t_cub3d *cub3d)
{
	int		i;

	i = 0;
	while (i < cub3d->screenheight - (lineh + lineo))
	{
		*(int *)(cub3d->img_texture + i * cub3d->size_line +
		(int)r * (cub3d->bits_per_pixel >> 3)) = cub3d->c_color;
		i++;
	}
}

void	draw3dfloor(float lineh, float lineo, int r, t_cub3d *cub3d)
{
	int		i;

	i = 0;
	while (i < lineo - 1)
	{
		*(int *)(cub3d->img_texture + ((int)(lineh + lineo) + i) *
		cub3d->size_line + (int)r *
		(cub3d->bits_per_pixel >> 3)) = cub3d->f_color;
		i++;
	}
}

void	paint(t_cub3d *cub3d, int j, int r, int y_texcoord)
{
	if (cub3d->side == 2)
		*(int *)(cub3d->img_texture + j * cub3d->size_line +
		(int)r * (cub3d->bits_per_pixel >> 3)) =
		*(int *)(cub3d->texture_adr0 + y_texcoord *
		cub3d->t_size_line + cub3d->x_texcoord *
		(cub3d->t_bits_per_pixel >> 3));
	if (cub3d->side == 3)
		*(int *)(cub3d->img_texture + j * cub3d->size_line +
		(int)r * (cub3d->bits_per_pixel >> 3)) =
		*(int *)(cub3d->texture_adr1 + y_texcoord *
		cub3d->t_size_line + cub3d->x_texcoord *
		(cub3d->t_bits_per_pixel >> 3));
	if (cub3d->side == 0)
		*(int *)(cub3d->img_texture + j * cub3d->size_line +
		(int)r * (cub3d->bits_per_pixel >> 3)) =
		*(int *)(cub3d->texture_adr2 + y_texcoord *
		cub3d->t_size_line + cub3d->x_texcoord *
		(cub3d->t_bits_per_pixel >> 3));
	if (cub3d->side == 1)
		*(int *)(cub3d->img_texture + j * cub3d->size_line +
		(int)r * (cub3d->bits_per_pixel >> 3)) =
		*(int *)(cub3d->texture_adr3 + y_texcoord *
		cub3d->t_size_line + cub3d->x_texcoord *
		(cub3d->t_bits_per_pixel >> 3));
}

void	drawwall3d(float lineh, float lineo, t_cub3d *cub3d, int r)
{
	float	textof;
	float	rem;
	int		y_texcoord;
	int		j;

	y_texcoord = 0;
	rem = 0;
	textof = 0;
	if (lineh > cub3d->screenheight)
	{
		textof = (lineh - cub3d->screenheight) / 2;
		rem = lineh;
		lineh = cub3d->screenheight;
		lineo = 0;
	}
	j = lineo;
	while (j < lineo + lineh)
	{
		if (rem)
			y_texcoord = ((textof + (j - lineo)) / rem * cub3d->t_height);
		else
			y_texcoord = (textof + (j - lineo)) / lineh * cub3d->t_height;
		paint(cub3d, j, r, y_texcoord);
		j++;
	}
}

void	draw3dscene(float raydist, int r, t_cub3d *cub3d)
{
	float	lineh;
	float	lineo;
	float	cosa;

	cosa = cub3d->posa - cub3d->raya;
	if (cosa < 0)
		cosa += 2 * M_PI;
	if (cosa > 2 * M_PI)
		cosa -= 2 * M_PI;
	cub3d->ray_array[r] = raydist;
	raydist = raydist * cos(cosa);
	lineh = ((cub3d->cell_x_len)
			* cub3d->screenheight) / raydist;
	lineo = (cub3d->screenheight >> 1) - (lineh / 2);
	if (lineo < 0)
		lineo = 0;
	drawwall3d(lineh, lineo, cub3d, r);
	if (lineh > cub3d->screenheight)
	{
		lineh = cub3d->screenheight;
		lineo = (cub3d->screenheight >> 1) - lineh / 2;
	}
	draw3dsky(lineh, lineo, r, cub3d);
	draw3dfloor(lineh, lineo, r, cub3d);
}
