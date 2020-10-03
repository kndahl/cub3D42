/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:43:11 by kdahl             #+#    #+#             */
/*   Updated: 2020/05/11 11:24:33 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;
	size_t	index;

	dest = (char *)dst;
	source = (char *)src;
	index = 0;
	if (dst == NULL || src == NULL)
		return (NULL);
	if (source < dest)
	{
		while (++index <= len)
			dest[len - index] = source[len - index];
	}
	else
		while (len > 0)
		{
			*dest = *source;
			dest++;
			source++;
			len--;
		}
	return (dst);
}
