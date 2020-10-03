/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 12:11:07 by kdahl             #+#    #+#             */
/*   Updated: 2020/05/04 23:46:11 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int ch, size_t n)
{
	size_t	index;
	char	*str_ptr;

	index = 0;
	if (str == NULL)
		return (0);
	str_ptr = (char *)str;
	while (index < n)
	{
		if (str_ptr[index] == (char)ch)
			return (&str_ptr[index]);
		index++;
	}
	return (0);
}
