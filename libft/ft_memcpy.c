/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 09:53:09 by kdahl             #+#    #+#             */
/*   Updated: 2020/05/16 15:38:21 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	unsigned char	*dest;
	unsigned char	*src;

	if (!num || destptr == srcptr)
		return (destptr);
	dest = (unsigned char *)destptr;
	src = (unsigned char *)srcptr;
	while (num)
	{
		*dest++ = *src++;
		num--;
	}
	return (destptr);
}
