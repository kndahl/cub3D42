/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 02:29:21 by kdahl             #+#    #+#             */
/*   Updated: 2020/05/13 14:50:27 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int ch)
{
	char	*ptr;

	ptr = (char *)s + ft_strlen(s);
	while (ptr >= s)
	{
		if (*ptr == (char)ch)
			return (ptr);
		ptr--;
	}
	return (NULL);
}
