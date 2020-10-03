/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:37:46 by kdahl             #+#    #+#             */
/*   Updated: 2020/10/03 13:14:14 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int x;
	int sum;
	int minusorplus;
	int counter;

	sum = 0;
	minusorplus = 1;
	counter = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
		minusorplus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		x = *str++ - 48;
		sum = sum * 10 + x;
		counter++;
	}
	if (counter < 1)
		return (256);
	if (counter >= 9)
		return (100000);
	return (sum * minusorplus);
}
