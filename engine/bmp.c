/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:59:25 by kdahl             #+#    #+#             */
/*   Updated: 2020/09/28 20:30:37 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static void		write_bmp_header(t_cub3d *cub3d, int fd, int size)
{
	unsigned char	header[54];

	ft_memset(header, 0, 54);
	header[0] = (unsigned char)'B';
	header[1] = (unsigned char)'M';
	set_int_in_char(header + 2, size);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	set_int_in_char(header + 18, cub3d->screenwidth);
	set_int_in_char(header + 22, cub3d->screenheight);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)24;
	write(fd, header, 54);
}

static void		write_data(t_cub3d *cub3d, int fd)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					pad;

	i = cub3d->screenheight;
	pad = (4 - (cub3d->screenwidth * 3) % 4) % 4;
	while (i >= 0)
	{
		j = 0;
		while (j < cub3d->screenwidth)
		{
			write(fd, &(*(int *)(cub3d->img_texture + i *
			cub3d->size_line + j * (cub3d->bits_per_pixel >> 3))), 3);
			if (pad > 0)
				write(fd, &zero, pad);
			j++;
		}
		i--;
	}
}

int				create_bitmap(t_cub3d *cub3d, char *name)
{
	int	fd;
	int	size;

	name = ft_strjoin(name, ".bmp");
	size = 54 + 3 * cub3d->screenwidth * cub3d->screenheight;
	if ((fd = open(name, O_WRONLY | O_CREAT |\
						O_TRUNC, 00755)) < 0)
		return (0);
	write_bmp_header(cub3d, fd, size);
	write_data(cub3d, fd);
	return (1);
}

int				bmp_parser(char **argv2, t_cub3d *cub3d)
{
	if (ft_strncmp(*argv2, "--save", 7) != 0)
		cub3d->error = 2;
	else
		cub3d->bmp = 1;
	return (cub3d->error);
}
