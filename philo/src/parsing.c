/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:30:16 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/09 10:01:22 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_parsing_atoi(int *n, char *str)
{
	int	nb;

	nb = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			if (ph_parsing_safeadd(&nb, *str - '0'))
				return (1);
		}
		else
			return (2);
		str++;
	}
	*n = nb;
	return (0);
}

int	ph_parsing_safeadd(int *a, int b)
{
	if (*a > (INT_MAX - b) / 10)
		return (1);
	*a = *a * 10 + b;
	return (0);
}
