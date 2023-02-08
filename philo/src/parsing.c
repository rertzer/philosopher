/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:30:16 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/08 10:17:46 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_parsing_atoi(int *n, char *str)
{

	*n = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			if (ph_parsing_safeadd(n, *str - '0'))
				return (1);
		else
			return (2);
		str++;
	}
	return (0);
}

int	ph_parsing_safeadd( int *a, int b)
{
	if (*a > (INT_MAX - b) / 10)
		return (1);
	*a = *a * 10 + b;
	return (0);
}

