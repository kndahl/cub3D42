/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 21:57:52 by kdahl             #+#    #+#             */
/*   Updated: 2020/05/12 11:46:32 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		index1;
	int		index2;

	if (s1 && s2)
	{
		if (!(str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		index1 = 0;
		index2 = 0;
		while (s1[index1])
			str[index1++] = s1[index2++];
		index2 = 0;
		while (s2[index2])
			str[index1++] = s2[index2++];
		str[index1] = '\0';
		return (str);
	}
	else
		return (NULL);
}
