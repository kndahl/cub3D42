/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 01:05:53 by kdahl             #+#    #+#             */
/*   Updated: 2020/09/14 16:39:14 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char		*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		index1;
	int		index2;

	if (!s1 && !s2)
		return (NULL);
	if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	if (!(str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	index1 = 0;
	index2 = 0;
	while (s1[index1])
		str[index1++] = s1[index2++];
	index2 = 0;
	while (s2[index2])
		str[index1++] = s2[index2++];
	str[index1] = '\0';
	return (str);
}

static int	create_newline(char **str, char **line, char *n_line)
{
	char	*remember;

	*line = ft_strdup(*str);
	if (*line == NULL)
		return (-1);
	if (*n_line == '\0')
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	remember = ft_strdup(n_line);
	if (remember == NULL)
		return (-1);
	free(*str);
	*str = remember;
	return (1);
}

static int	read_last(char **str, char **line, int read_process)
{
	char	*n_line;

	if (read_process < 0)
		return (-1);
	if ((*str) && (n_line = ft_strchr(*str, '\n')))
	{
		*n_line++ = '\0';
		return (create_newline(str, line, n_line));
	}
	if (*str)
	{
		*line = *str;
		*str = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*str[LIMITS];
	char		buf[BUFFER_SIZE + 1];
	char		*n_line;
	int			read_process;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0 || (read(fd, buf, 0) < 0))
		return (-1);
	while ((read_process = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_process] = '\0';
		n_line = ft_strjoin_gnl(str[fd], buf);
		free(str[fd]);
		str[fd] = n_line;
		if ((n_line = ft_strchr(str[fd], '\n')))
		{
			*n_line++ = '\0';
			return (create_newline(&str[fd], line, n_line));
		}
	}
	return (read_last(&str[fd], line, read_process));
}
