/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 01:22:47 by kdahl             #+#    #+#             */
/*   Updated: 2020/04/30 14:59:07 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	char	*begin;

	begin = str;
	if (str == NULL)
		return (NULL);
	while (n > 0)
	{
		*begin = c;
		begin++;
		n--;
	}
	return (str);
}
