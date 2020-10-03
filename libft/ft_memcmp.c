/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:37:53 by kdahl             #+#    #+#             */
/*   Updated: 2020/05/05 00:05:29 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t num)
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
	while (index < num)
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
