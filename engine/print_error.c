/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:28:57 by kdahl             #+#    #+#             */
/*   Updated: 2020/10/03 20:10:08 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_map_last(t_cub3d *cub3d)
{
	if (cub3d->screenheight && cub3d->screenheight &&
	cub3d->nopath[0] && cub3d->sopath[0] && cub3d->wepath[0] &&
	cub3d->eapath[0] && cub3d->spath[0] && cub3d->f_color &&
	cub3d->c_color)
		return (0);
	else
		return (1);
}

void	if_error(t_cub3d *cub3d)
{
	if (cub3d->map_found == -1)
		cub3d->error = 3;
	if (cub3d->player_foud != 1)
		cub3d->error = 7;
	if (!cub3d->screenwidth || !cub3d->screenheight
	|| !cub3d->f_color || !cub3d->c_color)
		cub3d->error = 2;
}

int		if_resol(t_cub3d *cub3d)
{
	if (cub3d->map_found == 1)
		return (2);
	if (cub3d->screenwidth > cub3d->max_screen_w)
		cub3d->screenwidth = cub3d->max_screen_w;
	if (cub3d->screenheight > cub3d->max_screen_h)
		cub3d->screenheight = cub3d->max_screen_h;
	if (cub3d->screenwidth && cub3d->screenheight)
		return (0);
	else
		return (2);
}

void	printerror(t_cub3d *cub3d, int errcase)
{
	if (cub3d->error == 1)
		write(2, "Map Error!\nInvalid map! Be sure that the \
map is surrounded by walls and symbols inside are correct!\n", 100);
	if (cub3d->error == 2)
		write(2, "Arguments Error!\nInvalid argument!\n", 35);
	if (cub3d->error == 7)
		write(2, "Player position error!.\n\
Be sure you have only one player inside the map and come back again!\n", 93);
	if (cub3d->error == 3)
		write(2, "Map Error!\nNo map inside!\n", 26);
	if (cub3d->error == 4)
		write(2, "Texture Error!\n", 15);
	if (cub3d->error == 256 || cub3d->error == 254)
		write(2, "Invalid Color!\n", 15);
	if (errcase == 1)
		write(2, "MLX init Error!\n", 16);
	if (errcase == 2)
		write(2, "Window creation Error!\n", 23);
	if (errcase == 3)
		write(2, "Image Error!\n", 13);
	if (errcase == 4)
		write(2, "No such texture in the program!\n", 32);
	exit(EXIT_FAILURE);
}

int		close_event(t_cub3d *cub3d)
{
	if (!cub3d->bmp)
		system("killall afplay");
	exit(0);
	return (0);
}
