/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 19:58:12 by kdahl             #+#    #+#             */
/*   Updated: 2020/05/23 11:11:20 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		new_word(const char *str, int i, char **dest, char c)
{
	int	length;
	int	go;

	length = 0;
	go = 0;
	while (*str == c)
	{
		str++;
		go++;
	}
	while (str[length] && str[length] != c)
		length++;
	if (length > 0)
	{
		if (!(dest[i] = (char *)malloc(sizeof(char) * (length + 1))))
			return (0);
		ft_strlcpy(dest[i], (char *)str, length + 1);
	}
	return (go + length);
}

static int		count_strings(char const *s, char c)
{
	int	counter;
	int	flag;

	counter = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			counter++;
		}
		s++;
	}
	return (counter);
}

char			**ft_split(char const *s, char c)
{
	int		len;
	int		index;
	int		str_num;
	char	**dest;

	index = 0;
	if (!(s))
		return (NULL);
	str_num = count_strings(s, c);
	if (!(dest = (char **)malloc(sizeof(char *) * (str_num + 1))))
		return (NULL);
	while (*s)
	{
		len = new_word(s, index++, dest, c);
		s += len;
	}
	dest[str_num] = 0;
	return (dest);
}
