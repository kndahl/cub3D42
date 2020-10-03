/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:29:53 by kdahl             #+#    #+#             */
/*   Updated: 2020/09/28 20:30:44 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_cub3d	init_cub3d_struct(void)
{
	t_cub3d		cub3d;

	cub3d.posx = 0;
	cub3d.posy = 0;
	cub3d.dirx = 0;
	cub3d.diry = 0;
	cub3d.posa = 0;
	cub3d.raya = 0;
	cub3d.error = 0;
	cub3d.pressed = 0;
	cub3d.side = 0;
	cub3d.sprites_num = 0;
	cub3d.sprites_pars = 0;
	cub3d.sprites_eaten = 0;
	cub3d.map_len = 0;
	cub3d.map_heigh = 0;
	cub3d.player_foud = 0;
	cub3d.map_found = -1;
	cub3d.play_music = 0;
	cub3d.screenwidth = 600;
	cub3d.screenheight = 600;
	cub3d.music = 1;
	return (cub3d);
}

float	dist(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int		gettexture(t_cub3d *cub3d)
{
	if (!(cub3d->t_img0 = mlx_xpm_file_to_image(cub3d->mlx_ptr, cub3d->nopath,
	&(cub3d->t_width), &(cub3d->t_height))))
		return (cub3d->error = 4);
	cub3d->texture_adr0 = mlx_get_data_addr(cub3d->t_img0,
	&(cub3d->t_bits_per_pixel), &(cub3d->t_size_line), &(cub3d->t_endian));
	if (!(cub3d->t_img1 = mlx_xpm_file_to_image(cub3d->mlx_ptr, cub3d->wepath,
	&(cub3d->t_width), &(cub3d->t_height))))
		return (cub3d->error = 4);
	cub3d->texture_adr1 = mlx_get_data_addr(cub3d->t_img1,
	&(cub3d->t_bits_per_pixel), &(cub3d->t_size_line), &(cub3d->t_endian));
	if (!(cub3d->t_img2 = mlx_xpm_file_to_image(cub3d->mlx_ptr, cub3d->eapath,
	&(cub3d->t_width), &(cub3d->t_height))))
		return (cub3d->error = 4);
	cub3d->texture_adr2 = mlx_get_data_addr(cub3d->t_img2,
	&(cub3d->t_bits_per_pixel), &(cub3d->t_size_line), &(cub3d->t_endian));
	if (!(cub3d->t_img3 = mlx_xpm_file_to_image(cub3d->mlx_ptr, cub3d->sopath,
	&(cub3d->t_width), &(cub3d->t_height))))
		return (cub3d->error = 4);
	cub3d->texture_adr3 = mlx_get_data_addr(cub3d->t_img3,
	&(cub3d->t_bits_per_pixel), &(cub3d->t_size_line), &(cub3d->t_endian));
	return (cub3d->error);
}

void	mlx_mainloop(t_cub3d *cub3d)
{
	mlx_put_image_to_window(cub3d->mlx_ptr,
		cub3d->window_ptr, cub3d->image_ptr, 0, 0);
	mlx_destroy_image(cub3d->mlx_ptr, cub3d->image_ptr);
	if (cub3d->bmp == 1)
	{
		drawrays3d(cub3d);
		rendersprites(cub3d);
		create_bitmap(cub3d, "cub3D");
		write(1, "Saved!\n", 7);
		close_event(cub3d);
	}
	mlx_expose_hook(cub3d->window_ptr, mouse_on, cub3d);
	mlx_loop_hook(cub3d->mlx_ptr, maprender, cub3d);
	mlx_hook(cub3d->window_ptr, 2, (1L << 1), keyboard, cub3d);
	mlx_hook(cub3d->window_ptr, 4, (1L << 8), key_shot, cub3d);
	mlx_hook(cub3d->window_ptr, 17, 0L, close_event, cub3d);
	mlx_loop(cub3d->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_cub3d		cub3d;

	if (argc == 2 || argc == 3)
	{
		cub3d = init_cub3d_struct();
		cub3d.error = argparser(&argv[1], &cub3d);
		check_window(&cub3d);
		cub3d.error = checkmapagain(&cub3d);
		cub3d.cell_x_len = 50;
		cub3d.cell_y_len = 50;
		if (argc == 3)
			cub3d.error = bmp_parser(&argv[2], &cub3d);
		if (!cub3d.error)
		{
			if (!cub3d.bmp)
				system("afplay -v 10 ./sound/pogonya_gimn.mp3& ");
			cub3d_engine(&cub3d);
		}
		else
			printerror(&cub3d, 0);
	}
	else
		write(2, "Arguments Error! Incorrect arguments number!\n", 45);
	return (0);
}
