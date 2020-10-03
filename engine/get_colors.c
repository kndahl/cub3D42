/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:20:20 by kdahl             #+#    #+#             */
/*   Updated: 2020/10/03 20:11:34 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned long	creatergb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static int		continue_rgb(int r, int g, int b, char *line)
{
	while (ft_isdigit(*line))
		line++;
	while (*line++)
	{
		if (ft_isdigit(*line))
			return (2);
	}
	if (r > 255 || g > 255 || b > 255)
		return (2);
	if (r < 0 || g < 0 || b < 0)
		return (2);
	return (0);
}

int				getfloorcolor(char *line, t_cub3d *cub3d)
{
	int		r;
	int		g;
	int		b;

	if (cub3d->f_color > 0)
		return (cub3d->error = 256);
	while (!(ft_isdigit(*line)))
		line++;
	if (*--line == '-')
		cub3d->error = 254;
	r = ft_atoi(line);
	while (*line != ',')
		line++;
	line++;
	g = ft_atoi(line);
	while (*line != ',')
		line++;
	line++;
	b = ft_atoi(line);
	if (continue_rgb(r, g, b, line))
		return (cub3d->error = 254);
	cub3d->f_color = creatergb(r, g, b);
	return (cub3d->error);
}

int				getceillingcolor(char *line, t_cub3d *cub3d)
{
	int		r;
	int		g;
	int		b;

	if (cub3d->c_color > 0)
		return (cub3d->error = 256);
	while (!(ft_isdigit(*line)))
		line++;
	if (*--line == '-')
		cub3d->error = 254;
	r = ft_atoi(line);
	while (*line != ',')
		line++;
	line++;
	g = ft_atoi(line);
	while (*line != ',')
		line++;
	line++;
	b = ft_atoi(line);
	if (continue_rgb(r, g, b, line))
		return (cub3d->error = 254);
	cub3d->c_color = creatergb(r, g, b);
	return (cub3d->error);
}
