/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:48:22 by kdahl             #+#    #+#             */
/*   Updated: 2020/09/25 17:52:43 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	eat_sprites(t_cub3d *cub3d)
{
	char	*ptr;

	ptr = ft_itoa(cub3d->sprites_eaten);
	mlx_string_put(cub3d->mlx_ptr, cub3d->window_ptr,
		20, 20, 000000, "Dictators Killed:");
	mlx_string_put(cub3d->mlx_ptr, cub3d->window_ptr, 190, 20,
		000000, ptr);
	free(ptr);
}

void	put_string_smallwindow(t_cub3d *cub3d)
{
	mlx_string_put(cub3d->mlx_ptr, cub3d->window_ptr,
		cub3d->screenwidth / 2.7, cub3d->screenheight / 2,
		16777215, "ALL ");
	mlx_string_put(cub3d->mlx_ptr, cub3d->window_ptr,
		cub3d->screenwidth / 2.27, cub3d->screenheight / 2,
		16711680, "DICTATORS ARE");
	mlx_string_put(cub3d->mlx_ptr, cub3d->window_ptr,
		cub3d->screenwidth / 1.48,
		cub3d->screenheight / 2, 16777215, "KILLED");
}

void	sprites_r_eaten(t_cub3d *cub3d)
{
	if (cub3d->screenwidth == 600 && cub3d->screenwidth == 600)
		put_string_smallwindow(cub3d);
	else
	{
		mlx_string_put(cub3d->mlx_ptr, cub3d->window_ptr,
			cub3d->screenwidth / 2.5, cub3d->screenheight / 2,
			16777215, "ALL ");
		mlx_string_put(cub3d->mlx_ptr, cub3d->window_ptr,
			cub3d->screenwidth / 2.2, cub3d->screenheight / 2,
			16711680, "DICTATORS ARE");
		mlx_string_put(cub3d->mlx_ptr, cub3d->window_ptr,
			cub3d->screenwidth / 1.6,
			cub3d->screenheight / 2, 16777215, "KILLED");
	}
}
