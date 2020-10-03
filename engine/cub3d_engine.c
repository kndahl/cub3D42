/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 21:00:13 by kdahl             #+#    #+#             */
/*   Updated: 2020/09/25 17:58:29 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			retry(int key, t_cub3d *cub3d)
{
	cub3d->rem = 1;
	if (key == 53)
	{
		system("killall afplay");
		exit(0);
	}
	return (0);
}

void		check_window(t_cub3d *cub3d)
{
	mlx_get_screen_size(cub3d->mlx_ptr,
	&cub3d->max_screen_w, &cub3d->max_screen_h);
	if (cub3d->max_screen_w <= 1440 &&
		cub3d->max_screen_h <= 900)
	{
		cub3d->screenwidth = 600;
		cub3d->screenwidth = 600;
	}
	else
	{
		cub3d->screenwidth = 900;
		cub3d->screenheight = 900;
	}
}

void		sounds_setting(t_cub3d *cub3d)
{
	if (cub3d->music)
	{
		cub3d->music = 0;
		system("killall afplay");
		return ;
	}
	if (!cub3d->music)
	{
		cub3d->music = 1;
		system("afplay -v 10 ./sound/pogonya_gimn.mp3& ");
		return ;
	}
}

void		cub3d_engine(t_cub3d *cub3d)
{
	if (!(cub3d->mlx_ptr = mlx_init()))
		printerror(cub3d, 1);
	if (!(cub3d->window_ptr = mlx_new_window(cub3d->mlx_ptr,
		cub3d->screenwidth, cub3d->screenheight, "Reycasting")))
		printerror(cub3d, 2);
	if (!(cub3d->image_ptr = mlx_new_image(cub3d->mlx_ptr,
		cub3d->screenwidth, cub3d->screenheight)))
		printerror(cub3d, 3);
	cub3d->img_texture = mlx_get_data_addr(cub3d->image_ptr,
		&cub3d->bits_per_pixel, &cub3d->size_line, &cub3d->endian);
	findplayer(cub3d);
	if ((cub3d->error = gettexture(cub3d)) ||
		(cub3d->error = getspritetext(cub3d) ||
		(cub3d->error = get_pistol(cub3d)) ||
		(cub3d->error = get_life(cub3d))))
		printerror(cub3d, 4);
	mlx_mainloop(cub3d);
}
