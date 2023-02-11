/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:30:16 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/11 10:54:05 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_parsing_atoi(t_phdata *phdata, char *str)
{
	int	nb;

	nb = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			nb = ph_parsing_safeadd(phdata, nb, *str - '0');
		else
			ph_exit_error(phdata, "non numeric value");
		str++;
	}
	return (nb);
}

int	ph_parsing_safeadd(t_phdata *phdata, int a, int b)
{
	if (a > (INT_MAX - b) / 10)
		ph_exit_error(phdata, "number to big, shall be an int");
	a = a * 10 + b;
	return (a);
}
