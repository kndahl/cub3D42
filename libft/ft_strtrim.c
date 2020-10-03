/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 23:33:16 by kdahl             #+#    #+#             */
/*   Updated: 2020/05/16 00:50:01 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	index;

	index = 0;
	while (src[index] && index < len)
	{
		dst[index] = src[index];
		index++;
	}
	while (index < len)
	{
		dst[index] = '\0';
		index++;
	}
	return (dst);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	begin;
	size_t	end;

	begin = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	end = ft_strlen(s1 + begin);
	if (end)
	{
		while (s1[begin + end - 1] != '\0' && \
		ft_strchr(set, s1[begin + end - 1]) != '\0')
			end--;
	}
	if (!(str = malloc(sizeof(char) * end + 1)))
		return (0);
	ft_strncpy(str, s1 + begin, end);
	str[end] = '\0';
	return (str);
}
