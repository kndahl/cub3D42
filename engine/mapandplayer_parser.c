/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapandplayer_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:24:50 by kdahl             #+#    #+#             */
/*   Updated: 2020/10/03 20:02:33 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			iswall(t_cub3d *cub3d, int key)
{
	if (key == 13)
	{
		if (cub3d->worldmap[(int)(((float)cub3d->mapheight /
		(cub3d->cell_y_len * cub3d->mapheight))
		* (cub3d->posy + (sin(cub3d->posa) * 5)))]
		[(int)(((float)cub3d->mapwidth / (cub3d->cell_x_len * cub3d->mapwidth))
		* (cub3d->posx + (cos(cub3d->posa) * 5)))] == 1)
			return (1);
	}
	if (key == 1)
	{
		if (cub3d->worldmap[(int)(((float)cub3d->mapheight /
		(cub3d->cell_y_len * cub3d->mapheight))
		* (cub3d->posy - (sin(cub3d->posa) * 5)))]
		[(int)(((float)cub3d->mapwidth / (cub3d->cell_x_len * cub3d->mapwidth))
		* (cub3d->posx - (cos(cub3d->posa) * 5)))] == 1)
			return (1);
	}
	if (key == 5)
	{
		if (go_straight(cub3d) || go_back(cub3d) || go_leftright(cub3d))
			return (1);
	}
	return (0);
}

static void	setposition(int mpwidth, int mpheight, int flag, t_cub3d *cub3d)
{
	if (flag == 7)
	{
		cub3d->worldmap[mpwidth][mpheight] = 0;
		cub3d->posx = mpheight * (cub3d->cell_y_len)
		+ ((cub3d->cell_y_len) >> 1);
		cub3d->posy = mpwidth * (cub3d->cell_x_len)
		+ ((cub3d->cell_x_len) >> 1);
		cub3d->dirx = cos(cub3d->posa) * 5;
		cub3d->diry = sin(cub3d->posa) * 5;
	}
	if (flag == 2)
	{
		cub3d->sprites[cub3d->sprites_num].sprite_x = mpheight
		* (cub3d->cell_y_len) + ((cub3d->cell_y_len) >> 1);
		cub3d->sprites[cub3d->sprites_num].sprite_y = mpwidth
		* (cub3d->cell_x_len) + ((cub3d->cell_x_len) >> 1);
		cub3d->sprites_num++;
	}
}

void		findplayer(t_cub3d *cub3d)
{
	int	mpwidth;
	int	mpheight;

	mpwidth = 0;
	mpheight = 0;
	while (mpwidth < cub3d->mapwidth)
	{
		mpheight = 0;
		while (mpheight < cub3d->map_len)
		{
			if (cub3d->worldmap[mpwidth][mpheight] == 7)
				setposition(mpwidth, mpheight, 7, cub3d);
			if (cub3d->worldmap[mpwidth][mpheight] == 2)
				setposition(mpwidth, mpheight, 2, cub3d);
			mpheight++;
		}
		mpwidth++;
	}
	cub3d->pressed = 1;
}

static void	chekiflocked(int mpwidth, int mpheight, t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	s;
	int	w;

	i = mpheight - 2;
	j = mpheight + 1;
	mpwidth--;
	while (i++ < j)
	{
		if (cub3d->worldmap[mpwidth][i] == 3
		|| cub3d->worldmap[mpwidth][i] == 0)
			cub3d->error = 1;
	}
	mpwidth++;
	mpwidth++;
	s = mpheight - 2;
	w = mpheight + 1;
	while (s++ < w)
	{
		if (cub3d->worldmap[mpwidth][s] == 3
		|| cub3d->worldmap[mpwidth][s] == 0)
			cub3d->error = 1;
	}
}

static int		if_subjects(int mpwidth, int mpheight, t_cub3d *cub3d)
{
	if (cub3d->worldmap[mpwidth][mpheight] == 8 ||
	cub3d->worldmap[mpwidth][mpheight] == 7 ||
	cub3d->worldmap[mpwidth][mpheight] == 2)
		return (1);
	else
		return (0);
}

int			checkmapagain(t_cub3d *cub3d)
{
	int	mpwidth;
	int	mpheight;

	mpwidth = 0;
	mpheight = 0;
	while (mpwidth++ < cub3d->mapwidth)
	{
		mpheight = 0;
		while (mpheight++ < cub3d->map_len)
		{
			if (if_subjects(mpwidth, mpheight, cub3d))
			{
				chekiflocked(mpwidth, mpheight, cub3d);
				if (cub3d->worldmap[mpwidth][--mpheight] == 3
				|| cub3d->worldmap[mpwidth][mpheight] == 0)
					cub3d->error = 1;
				mpheight++;
				if (cub3d->worldmap[mpwidth][++mpheight] == 3
				|| cub3d->worldmap[mpwidth][mpheight] == 0)
					cub3d->error = 1;
				mpheight--;
			}
		}
	}
	return (cub3d->error);
}
