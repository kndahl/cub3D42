/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 15:58:09 by kdahl             #+#    #+#             */
/*   Updated: 2020/05/10 23:40:36 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t			index;
	unsigned char	*str1;
	unsigned char	*str2;
	int				res;

	index = 0;
	res = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (index < num && ((str1[index]) || (str2[index])))
	{
		if (str1[index] > str2[index])
			return (str1[index] - str2[index]);
		if (str1[index] < str2[index])
			return (str1[index] - str2[index]);
		if (str1[index] == str2[index])
			res = 0;
		index++;
	}
	return (res);
}
