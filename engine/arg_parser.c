/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:17:33 by kdahl             #+#    #+#             */
/*   Updated: 2020/10/03 20:07:14 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int		checkresolution(char *line, t_cub3d *cub3d)
// {
// 	if (*line == 'R')
// 	{
// 		if (cub3d->screenheight > 0 && cub3d->screenwidth > 0)
// 			return (2);
// 		line++;
// 		while (*line == ' ' || *line == '\t')
// 			line++;
// 		if (ft_isdigit(*line))
// 			cub3d->screenwidth = ft_atoi(line);
// 		while (ft_isdigit(*line))
// 			line++;
// 		while (*line == ' ' || *line == '\t')
// 			line++;
// 		if (ft_isdigit(*line))
// 			cub3d->screenheight = ft_atoi(line);
// 		while (ft_isdigit(*line))
// 			line++;
// 		while (*line)
// 		{
// 			if (ft_isdigit(*line++))
// 				return (2);
// 		}
// 	}
// 	return (if_resol(cub3d));
// }

char	checkplayermap(char word, t_cub3d *cub3d)
{
	if (cub3d->player_foud == 1 && (word == 'E' ||
				word == 'W' || word == 'N' || word == 'S'))
	{
		cub3d->error = 7;
		printerror(cub3d, 0);
	}
	if (word == 'E')
		word = setplayerangle(0.0, cub3d);
	if (word == 'W')
		word = setplayerangle(M_PI, cub3d);
	if (word == 'N')
		word = setplayerangle(3 * M_PI / 2, cub3d);
	if (word == 'S')
		word = setplayerangle(M_PI / 2, cub3d);
	return (word);
}

int		checkmap(char *line, t_cub3d *cub3d)
{
	int		len;
	char	word;

	len = 0;
	if (*line == '0')
		cub3d->error = 1;
	if (*line == '1' || *line == '3')
	{
		while (*line && !cub3d->lastmapstr)
		{
			word = *line;
			*line = checkmapifcase(line, cub3d);
			if (*line == '2')
				cub3d->sprites_pars++;
			word = checkplayermap(*line, cub3d);
			cub3d->worldmap[cub3d->mapwidth][cub3d->mapheight] = ft_atoi(&word);
			cub3d->mapheight++;
			line++;
			len++;
		}
		if (len > cub3d->map_len)
			cub3d->map_len = len;
	}
	return (cub3d->error);
}

int		checkline(char *line, t_cub3d *cub3d)
{
	if (cub3d->map_found == 1 && *line == '\0')
		cub3d->error = 1;
	while (*line == ' ' || *line == '\t')
		*line = '3';
	// if (*line == 'R')
	// 	cub3d->error = checkresolution(line, cub3d);
	if (*line == '1' || *line == '3' || *line == '0')
	{
		cub3d->map_found = 1;
		cub3d->map_heigh++;
		cub3d->mapheight = 0;
		cub3d->mapwidth++;
		cub3d->error = checkmap(line, cub3d);
		if (is_map_last(cub3d))
			return (cub3d->error = 2);
	}
	if (*line == 'N' || *line == 'S' || *line == 'W' ||
		*line == 'E' || *line == 'F' || *line == 'C')
		cub3d->error = getpath(line, cub3d);
	return (cub3d->error);
}

char	*get_arg_name(char *argv, char *format)
{
	int		len;

	len = ft_strlen(argv);
	ft_strlcpy(format, &argv[len - 4], 5);
	return (format);
}

int		argparser(char **argv, t_cub3d *cub3d)
{
	int		fd;
	int		read;
	char	*line;
	char	format[5];

	if (ft_strncmp(".cub", get_arg_name(argv[0], format), 3) != 0)
		return (cub3d->error = 2);
	read = 1;
	fd = open(*argv, O_RDONLY);
	if (fd == -1)
		return (cub3d->error = 2);
	while (read == 1)
	{
		read = get_next_line(fd, &line);
		if (checkline(line, cub3d) == -1)
			read = -1;
		free(line);
	}
	close(fd);
	if_error(cub3d);
	return (cub3d->error);
}
