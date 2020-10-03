/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 03:19:51 by kdahl             #+#    #+#             */
/*   Updated: 2020/05/05 00:06:41 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	index;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		src_len += size;
	else
		src_len += dst_len;
	index = 0;
	while ((src[index]) && dst_len + 1 < size)
	{
		dst[dst_len] = src[index];
		dst_len++;
		index++;
	}
	dst[dst_len] = '\0';
	return (src_len);
}
