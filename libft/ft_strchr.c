/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:42:49 by kdahl             #+#    #+#             */
/*   Updated: 2020/05/04 23:58:41 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int ch)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == ch)
			return ((char *)&s[index]);
		index++;
	}
	if (s[index] == '\0' && (char)ch == '\0')
		return ((char *)&s[index]);
	return (NULL);
}
