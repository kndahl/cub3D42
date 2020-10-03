/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:16:38 by kdahl             #+#    #+#             */
/*   Updated: 2020/09/09 14:28:26 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		getpath(char *line, t_cub3d *cub3d)
{
	if (*line == 'N')
		cub3d->error = path2north(line, cub3d);
	if (*line == 'S')
		cub3d->error = path2south(line, cub3d);
	if (*line == 'W')
		cub3d->error = path2west(line, cub3d);
	if (*line == 'E')
		cub3d->error = path2east(line, cub3d);
	if (*line == 'F')
		cub3d->error = getfloorcolor(line, cub3d);
	if (*line == 'C')
		cub3d->error = getceillingcolor(line, cub3d);
	return (cub3d->error);
}

char	setplayerangle(float angle, t_cub3d *cub3d)
{
	cub3d->player_foud = 1;
	cub3d->posa = angle;
	return ('7');
}

char	checkmapifcase(char *line, t_cub3d *cub3d)
{
	if (*line == ' ')
		*line = '3';
	if (*line == '0')
		*line = '8';
	if (*line != '1' && *line != '8' &&
		*line != 'E' && *line != 'W' &&
		*line != 'S' && *line != 'N' &&
		*line != '2' && *line != '3')
	{
		cub3d->error = 1;
	}
	return (*line);
}
