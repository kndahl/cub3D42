/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:40:12 by kdahl             #+#    #+#             */
/*   Updated: 2020/05/05 00:37:57 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int ch, size_t num)
{
	size_t			index;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	index = 0;
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	while (index < num)
	{
		dst_ptr[index] = src_ptr[index];
		if (dst_ptr[index] == (unsigned char)(ch))
			return (dst + index + 1);
		index++;
	}
	return (0);
}
