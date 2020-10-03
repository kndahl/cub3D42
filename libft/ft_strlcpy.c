/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 15:28:25 by kdahl             #+#    #+#             */
/*   Updated: 2020/05/12 11:24:15 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t index;

	index = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while ((src[index]) && size - 1 > 0)
		{
			dst[index] = src[index];
			index++;
			size--;
		}
		dst[index] = '\0';
	}
	while (src[index])
		index++;
	return (index);
}
