/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:42:19 by kdahl             #+#    #+#             */
/*   Updated: 2020/09/14 15:59:08 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		pistol(t_cub3d *cub3d)
{
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->window_ptr,
	cub3d->pistol_ptr2, cub3d->screenwidth / 2
	- cub3d->p_width / 2, cub3d->screenheight - cub3d->p_width);
}

float		get_aim(t_cub3d *cub3d)
{
	float	aim;

	aim = 0.01;
	if (cub3d->sprites[cub3d->sprites_num].sprite_dist
	<= 100 && cub3d->sprites[cub3d->sprites_num].sprite_dist >= 50)
		aim = 0.2;
	if (cub3d->sprites[cub3d->sprites_num].sprite_dist <= 50)
		aim = 0.3;
	return (aim);
}

int			key_shot(int un_use, int x, int y, t_cub3d *cub3d)
{
	int		start;

	start = 0;
	un_use = x + y;
	if (cub3d->damage < 100)
	{
		system("afplay -v 30 ./sound/shot.mp3&");
		while (start++ < 300)
			mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->window_ptr,
			cub3d->pistol_ptr3, cub3d->screenwidth / 2 -
			cub3d->p_width / 2, cub3d->screenheight - cub3d->p_width);
		start = 0;
		while (start++ < 500)
			mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->window_ptr,
			cub3d->pistol_ptr4, cub3d->screenwidth / 2 -
			cub3d->p_width / 2, cub3d->screenheight - cub3d->p_width);
		cub3d->pressed = 1;
		cub3d->gun_pos = 1;
	}
	return (0);
}

int			shooting_process(t_cub3d *cub3d)
{
	float	aim;

	aim = get_aim(cub3d);
	if ((cub3d->sprites[cub3d->sprites_num].sprite_dir - aim
	< cub3d->posa && cub3d->sprites[cub3d->sprites_num].sprite_dir
	+ aim > cub3d->posa) && cub3d->gun_pos == 1)
	{
		if (cub3d->sprites[cub3d->sprites_num].sprites_die
		== 0 && cub3d->sprites_eaten < cub3d->sprites_pars - 1)
			system("afplay -v 50 ./sound/ploho.mp3&");
		else
			system("afplay -v 50 ./sound/vot-i-vse.mp3&");
		cub3d->sprites[cub3d->sprites_num].sprites_die = 1;
		return (1);
	}
	if (cub3d->sprites[cub3d->sprites_num].sprite_dist < 30)
		cub3d->damage += 1;
	return (0);
}

void		damage_process(t_cub3d *cub3d)
{
	if (cub3d->sprites_eaten < cub3d->sprites_pars && cub3d->damage < 100)
		eat_sprites(cub3d);
	if (cub3d->sprites_eaten == cub3d->sprites_pars && cub3d->damage < 100)
		sprites_r_eaten(cub3d);
	if (cub3d->damage < 100)
		pistol(cub3d);
	if (cub3d->damage > 100 && !cub3d->dam_end)
	{
		system("afplay -v 50 ./sound/mjaso.mp3&");
		cub3d->dam_end = 1;
	}
}
