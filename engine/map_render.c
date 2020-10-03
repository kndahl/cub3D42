/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:27:54 by kdahl             #+#    #+#             */
/*   Updated: 2020/09/25 17:59:37 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	image_dead(t_cub3d *cub3d)
{
	if (cub3d->screenwidth == 600)
		mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->window_ptr,
		cub3d->dead, 80, 85);
	else
		mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->window_ptr,
		cub3d->dead, 200, 200);
}

int			maprender(t_cub3d *cub3d)
{
	mouse(cub3d);
	if (cub3d->pressed == 1)
	{
		if (!(cub3d->image_ptr = mlx_new_image(cub3d->mlx_ptr,
			cub3d->screenwidth, cub3d->screenheight)))
			printerror(cub3d, 3);
		cub3d->img_texture = mlx_get_data_addr(cub3d->image_ptr,
			&cub3d->bits_per_pixel, &cub3d->size_line, &cub3d->endian);
		drawrays3d(cub3d);
		rendersprites(cub3d);
		mlx_put_image_to_window(cub3d->mlx_ptr,
			cub3d->window_ptr, cub3d->image_ptr, 0, 0);
		damage_process(cub3d);
		life(cub3d);
		if (cub3d->damage > 100)
		{
			image_dead(cub3d);
			mlx_hook(cub3d->window_ptr, 2, (1L << 1), retry, cub3d);
		}
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->image_ptr);
	}
	return (0);
}

void		getsouth(char *line, t_cub3d *cub3d)
{
	if (*++line == ' ')
	{
		while (*line++ != 'x')
		{
			if (*line == 'x' && *++line == 'p'
			&& *++line == 'm' && (*++line == '\0' || *line == ' '))
			{
				if (*line == ' ')
					line--;
				while (*--line != ' ')
					cub3d->rem++;
				line++;
				break ;
			}
		}
		while (cub3d->index < cub3d->rem + 1)
			cub3d->sopath[cub3d->index++] = *line++;
		cub3d->sopath[cub3d->index] = '\0';
	}
}

int			mouse_on(t_cub3d *cub3d)
{
	cub3d->mouse_on = 1;
	return (0);
}
