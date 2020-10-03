/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 13:32:44 by kdahl             #+#    #+#             */
/*   Updated: 2020/09/25 17:31:14 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calcspritesparams(t_cub3d *cub3d, float fov)
{
	cub3d->sprites[cub3d->sprites_num].sprite_dist =
	dist(cub3d->sprites[cub3d->sprites_num].sprite_x,
	cub3d->sprites[cub3d->sprites_num].sprite_y, cub3d->posx, cub3d->posy);
	cub3d->sprites[cub3d->sprites_num].sprite_screen_size =
	(50 / cub3d->sprites[cub3d->sprites_num].sprite_dist)
	* (cub3d->screenwidth >> 1) / tan(fov / 2);
	cub3d->sprites[cub3d->sprites_num].h_offset =
	(cub3d->sprites[cub3d->sprites_num].sprite_dir
	- cub3d->posa) * (cub3d->screenwidth) / (fov)
	+ ((cub3d->screenwidth) >> 1)
	- cub3d->sprites[cub3d->sprites_num].sprite_screen_size / 2;
	cub3d->sprites[cub3d->sprites_num].v_offset = (cub3d->screenheight >> 1)
	- cub3d->sprites[cub3d->sprites_num].sprite_screen_size / 2;
}

void	drawit(int i, int j, t_cub3d *cub3d)
{
	int		x_text;
	int		y_text;
	int		color;

	x_text = i * cub3d->st_width /
	cub3d->sprites[cub3d->sprites_num].sprite_screen_size;
	y_text = j * cub3d->st_height /
	cub3d->sprites[cub3d->sprites_num].sprite_screen_size;
	color = *(int *)(cub3d->stexture_adr + y_text *
	cub3d->st_size_line + x_text * (cub3d->st_bits_per_pixel >> 3));
	if ((color & 0x00FFFFFF) != 16711935)
		*(int *)(cub3d->img_texture +
		(cub3d->sprites[cub3d->sprites_num].v_offset + j)
		* cub3d->size_line +
		(cub3d->sprites[cub3d->sprites_num].h_offset + i)
		* (cub3d->bits_per_pixel >> 3)) = color;
}

void	drawsprite2(t_cub3d *cub3d, int j, int i)
{
	while (j < cub3d->sprites[cub3d->sprites_num].sprite_screen_size)
	{
		if (cub3d->sprites[cub3d->sprites_num].v_offset + j < 0
		|| cub3d->sprites[cub3d->sprites_num].v_offset
		+ j >= cub3d->screenheight)
		{
			++j;
			continue;
		}
		drawit(i, j, cub3d);
		j++;
	}
}
