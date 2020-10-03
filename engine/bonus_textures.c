/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:07:31 by kdahl             #+#    #+#             */
/*   Updated: 2020/09/14 16:13:22 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				get_pistol(t_cub3d *cub3d)
{
	char	*relative_path1;
	char	*relative_path2;
	char	*relative_path3;
	char	*relative_path4;

	relative_path1 = "./textures/gun.xpm";
	relative_path2 = "./textures/gun2.xpm";
	relative_path3 = "./textures/gun3.xpm";
	relative_path4 = "./textures/gun4.xpm";
	if (!(cub3d->pistol_ptr = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	relative_path1, &cub3d->p_width, &cub3d->p_height)))
		return (cub3d->error = 4);
	if (!(cub3d->pistol_ptr2 = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	relative_path2, &cub3d->p_width, &cub3d->p_height)))
		return (cub3d->error = 4);
	if (!(cub3d->pistol_ptr3 = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	relative_path3, &cub3d->p_width, &cub3d->p_height)))
		return (cub3d->error = 4);
	if (!(cub3d->pistol_ptr4 = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	relative_path4, &cub3d->p_width, &cub3d->p_height)))
		return (cub3d->error = 4);
	return (0);
}

static int		get_life_contin(t_cub3d *cub3d)
{
	if (!(cub3d->life_ptr50 = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	"./textures/health50.xpm", &cub3d->l_width, &cub3d->l_height)))
		return (cub3d->error = 4);
	if (!(cub3d->life_ptr40 = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	"./textures/health40.xpm", &cub3d->l_width, &cub3d->l_height)))
		return (cub3d->error = 4);
	if (!(cub3d->life_ptr30 = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	"./textures/health30.xpm", &cub3d->l_width, &cub3d->l_height)))
		return (cub3d->error = 4);
	if (!(cub3d->life_ptr20 = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	"./textures/health20.xpm", &cub3d->l_width, &cub3d->l_height)))
		return (cub3d->error = 4);
	if (!(cub3d->life_ptr10 = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	"./textures/health10.xpm", &cub3d->l_width, &cub3d->l_height)))
		return (cub3d->error = 4);
	if (!(cub3d->life_ptr0 = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	"./textures/health0.xpm", &cub3d->l_width, &cub3d->l_height)))
		return (cub3d->error = 4);
	return (0);
}

int				get_life(t_cub3d *cub3d)
{
	if (!(cub3d->life_ptr100 = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	"./textures/health100.xpm", &cub3d->l_width, &cub3d->l_height)))
		return (cub3d->error = 4);
	if (!(cub3d->life_ptr90 = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	"./textures/health90.xpm", &cub3d->l_width, &cub3d->l_height)))
		return (cub3d->error = 4);
	if (!(cub3d->life_ptr80 = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	"./textures/health80.xpm", &cub3d->l_width, &cub3d->l_height)))
		return (cub3d->error = 4);
	if (!(cub3d->life_ptr70 = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	"./textures/health70.xpm", &cub3d->l_width, &cub3d->l_height)))
		return (cub3d->error = 4);
	if (!(cub3d->life_ptr60 = mlx_xpm_file_to_image(cub3d->mlx_ptr,
	"./textures/health60.xpm", &cub3d->l_width, &cub3d->l_height)))
		return (cub3d->error = 4);
	cub3d->error = get_life_contin(cub3d);
	return (0);
}

static void		life_contin(t_cub3d *cub3d)
{
	if (cub3d->damage >= 60 && cub3d->damage < 70)
		mlx_put_image_to_window(cub3d->mlx_ptr,
		cub3d->window_ptr, cub3d->life_ptr40, 20, 20);
	if (cub3d->damage >= 70 && cub3d->damage < 80)
		mlx_put_image_to_window(cub3d->mlx_ptr,
		cub3d->window_ptr, cub3d->life_ptr30, 20, 20);
	if (cub3d->damage >= 80 && cub3d->damage < 90)
		mlx_put_image_to_window(cub3d->mlx_ptr,
		cub3d->window_ptr, cub3d->life_ptr20, 20, 20);
	if (cub3d->damage >= 90 && cub3d->damage < 100)
		mlx_put_image_to_window(cub3d->mlx_ptr,
		cub3d->window_ptr, cub3d->life_ptr10, 20, 20);
	if (cub3d->damage >= 100)
		mlx_put_image_to_window(cub3d->mlx_ptr,
		cub3d->window_ptr, cub3d->life_ptr0, 20, 20);
}

void			life(t_cub3d *cub3d)
{
	if (cub3d->damage < 10)
		mlx_put_image_to_window(cub3d->mlx_ptr,
		cub3d->window_ptr, cub3d->life_ptr100, 20, 20);
	if (cub3d->damage >= 10 && cub3d->damage < 20)
		mlx_put_image_to_window(cub3d->mlx_ptr,
		cub3d->window_ptr, cub3d->life_ptr90, 20, 20);
	if (cub3d->damage >= 20 && cub3d->damage < 30)
		mlx_put_image_to_window(cub3d->mlx_ptr,
		cub3d->window_ptr, cub3d->life_ptr80, 20, 20);
	if (cub3d->damage >= 30 && cub3d->damage < 40)
		mlx_put_image_to_window(cub3d->mlx_ptr,
		cub3d->window_ptr, cub3d->life_ptr70, 20, 20);
	if (cub3d->damage >= 40 && cub3d->damage < 50)
		mlx_put_image_to_window(cub3d->mlx_ptr,
		cub3d->window_ptr, cub3d->life_ptr60, 20, 20);
	if (cub3d->damage >= 50 && cub3d->damage < 60)
		mlx_put_image_to_window(cub3d->mlx_ptr,
		cub3d->window_ptr, cub3d->life_ptr50, 20, 20);
	life_contin(cub3d);
}
