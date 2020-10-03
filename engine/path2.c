/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:11:21 by kdahl             #+#    #+#             */
/*   Updated: 2020/10/03 20:02:26 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int		spath_body(char *line, t_cub3d *cub3d)
{
	while (*line++ != 'x')
	{
		if (*line == 'x' && *++line == 'p' &&
		*++line == 'm' && (*++line == '\0' || *line == ' '))
		{
			while (*line != 'm')
				line--;
			while (*--line != ' ')
				cub3d->rem++;
			line++;
			break ;
		}
		if (*line == '\0')
			return (cub3d->error = 2);
	}
	while (cub3d->index < cub3d->rem + 1)
		cub3d->spath[cub3d->index++] = *line++;
	cub3d->spath[cub3d->index] = '\0';
	return (cub3d->error);
}

static int		nopath_body(char *line, t_cub3d *cub3d)
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
		if (*line == '\0')
			return (cub3d->error = 2);
	}
	while (cub3d->index < cub3d->rem + 1)
		cub3d->nopath[cub3d->index++] = *line++;
	cub3d->nopath[cub3d->index] = '\0';
	return (cub3d->error);
}

static int		wepath_body(char *line, t_cub3d *cub3d)
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
		if (*line == '\0')
			return (cub3d->error = 2);
	}
	while (cub3d->index < cub3d->rem + 1)
		cub3d->wepath[cub3d->index++] = *line++;
	cub3d->wepath[cub3d->index] = '\0';
	return (cub3d->error);
}

static int		eapath_body(char *line, t_cub3d *cub3d)
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
		if (*line == '\0')
			return (cub3d->error = 2);
	}
	while (cub3d->index < cub3d->rem + 1)
		cub3d->eapath[cub3d->index++] = *line++;
	cub3d->eapath[cub3d->index] = '\0';
	return (cub3d->error);
}

int		path2sprite(char *line, t_cub3d *cub3d)
{
	cub3d->rem = 0;
	cub3d->index = 0;
	if (cub3d->spath[0])
		return (cub3d->error = 4);
	while (*line != '.')
		line++;
	if (*line == ' ' || *line == '.')
		cub3d->error = spath_body(line, cub3d);
	while (line[cub3d->index++])
	{
		if (ft_isalpha(line[cub3d->index]) || ft_isdigit(line[cub3d->index]))
			cub3d->error = 2;
	}
	return (cub3d->error);
}

int		path2north(char *line, t_cub3d *cub3d)
{
	cub3d->rem = 0;
	cub3d->index = 0;
	if (!(*++line == 'O' || *line++ == 'o'))
		cub3d->error = 4;
	if (cub3d->nopath[0])
		return (cub3d->error = 4);
	if (*++line == ' ')
		cub3d->error = nopath_body(line, cub3d);
	while (line[cub3d->index++])
	{
		if (ft_isalpha(line[cub3d->index]) || ft_isdigit(line[cub3d->index]))
			cub3d->error = 2;
	}
	return (cub3d->error);
}

int		path2south(char *line, t_cub3d *cub3d)
{
	cub3d->rem = 0;
	cub3d->index = 0;
	if (*++line == ' ' || *line == '.')
	{
		cub3d->error = path2sprite(line, cub3d);
		return (cub3d->error);
	}
	if (!(*line == 'O' || *line == 'o'))
		return (cub3d->error = 4);
	if (cub3d->sopath[0])
		return (cub3d->error = 4);
	getsouth(line, cub3d);
	if (cub3d->spath[0])
	{
		while (line[cub3d->index++])
		{
			if (ft_isalpha(line[cub3d->index])
			|| ft_isdigit(line[cub3d->index]))
				cub3d->error = 2;
		}
	}
	return (cub3d->error);
}

int		path2west(char *line, t_cub3d *cub3d)
{
	cub3d->rem = 0;
	cub3d->index = 0;
	if (!(*++line == 'E' || *line == 'e'))
		cub3d->error = 4;
	if (cub3d->wepath[0])
		return (cub3d->error = 4);
	if (*++line == ' ')
		cub3d->error = wepath_body(line, cub3d);
	while (line[cub3d->index++])
	{
		if (ft_isalpha(line[cub3d->index]) || ft_isdigit(line[cub3d->index]))
			cub3d->error = 2;
	}
	return (cub3d->error);
}

int		path2east(char *line, t_cub3d *cub3d)
{
	cub3d->rem = 0;
	cub3d->index = 0;
	if (!(*++line == 'A' || *line == 'a'))
		cub3d->error = 4;
	if (cub3d->eapath[0])
		return (cub3d->error = 4);
	if (*++line == ' ')
		cub3d->error = eapath_body(line, cub3d);
	while (line[cub3d->index++])
	{
		if (ft_isalpha(line[cub3d->index]) || ft_isdigit(line[cub3d->index]))
			cub3d->error = 2;
	}
	return (cub3d->error);
}