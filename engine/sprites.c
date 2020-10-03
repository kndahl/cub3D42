/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:14:02 by kdahl             #+#    #+#             */
/*   Updated: 2020/09/14 16:14:58 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		getspritetext(t_cub3d *cub3d)
{
	if (!(cub3d->st_img = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	cub3d->spath, &(cub3d->st_width), &(cub3d->st_height))))
		return (cub3d->error = 4);
	if (!(cub3d->dead = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	"./textures/wasted.xpm", &(cub3d->f_width), &(cub3d->f_height))))
		return (cub3d->error = 4);
	cub3d->stexture_adr = mlx_get_data_addr(cub3d->st_img,
	&(cub3d->st_bits_per_pixel),
	&(cub3d->st_size_line), &(cub3d->st_endian));
	return (cub3d->error);
}

void	calcsprite(t_cub3d *cub3d)
{
	cub3d->sprites_num = 0;
	if (cub3d->sprites_eaten == cub3d->sprites_pars)
		return ;
	while (cub3d->sprites_num < cub3d->sprites_pars)
	{
		if (cub3d->sprites[cub3d->sprites_num].sprites_die == 1)
		{
			++cub3d->sprites_num;
			continue ;
		}
		cub3d->sprites[cub3d->sprites_num].sprite_dir =
		atan2(cub3d->sprites[cub3d->sprites_num].sprite_y
		- cub3d->posy, cub3d->sprites[cub3d->sprites_num].sprite_x
			- cub3d->posx);
		while (cub3d->sprites[cub3d->sprites_num].sprite_dir
		- cub3d->posa > M_PI)
			cub3d->sprites[cub3d->sprites_num].sprite_dir -= 2 * M_PI;
		while (cub3d->sprites[cub3d->sprites_num].sprite_dir
		- cub3d->posa < -M_PI)
			cub3d->sprites[cub3d->sprites_num].sprite_dir += 2 * M_PI;
		calcspritesparams(cub3d, M_PI / 3);
		cub3d->sprites_num++;
	}
}

void	sortsprites(t_cub3d *cub3d)
{
	int			j;
	t_sprites	temp;

	cub3d->sprites_num = 0;
	while (cub3d->sprites_num < cub3d->sprites_pars)
	{
		j = 0;
		while (j < cub3d->sprites_num)
		{
			if (cub3d->sprites[j].sprite_dist
			< cub3d->sprites[j + 1].sprite_dist)
			{
				temp = cub3d->sprites[j];
				cub3d->sprites[j] = cub3d->sprites[j + 1];
				cub3d->sprites[j + 1] = temp;
			}
			j++;
		}
		cub3d->sprites_num++;
	}
}

void	drawsprite(t_cub3d *cub3d)
{
	int		i;
	int		j;

	i = 0;
	while (i < cub3d->sprites[cub3d->sprites_num].sprite_screen_size)
	{
		if (cub3d->sprites[cub3d->sprites_num].h_offset + i < 0
		|| cub3d->sprites[cub3d->sprites_num].h_offset
		+ i >= cub3d->screenwidth)
		{
			++i;
			continue;
		}
		if (cub3d->ray_array[cub3d->sprites[cub3d->sprites_num].h_offset + i]
		< cub3d->sprites[cub3d->sprites_num].sprite_dist)
		{
			++i;
			continue;
		}
		j = 0;
		drawsprite2(cub3d, j, i);
		i++;
	}
}

void	rendersprites(t_cub3d *cub3d)
{
	int		counter;

	counter = 0;
	calcsprite(cub3d);
	sortsprites(cub3d);
	cub3d->sprites_num = 0;
	while (cub3d->sprites_num < cub3d->sprites_pars)
	{
		if (shooting_process(cub3d))
			break ;
		if (cub3d->sprites[cub3d->sprites_num].sprites_die != 1)
		{
			counter++;
			drawsprite(cub3d);
		}
		cub3d->sprites_num++;
	}
	cub3d->gun_pos = 0;
	cub3d->sprites_eaten = cub3d->sprites_pars - counter;
}
