/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:58:47 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/19 12:44:52 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long int	ph_clock_timestamp(t_phdata *phdata)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - phdata->time_start);
}

void	ph_clock_ontime(t_phdata *phdata)
{
	int	i;

	ph_semaphore_wait(phdata, phdata->speeking);
	if (ph_clock_timestamp(phdata) > phdata->last_meal + phdata->time_to_die)
	{
		printf("%ld %d died\n", ph_clock_timestamp(phdata), phdata->number);
		i = -1;
		while (++i < phdata->nb_of_philo)
			ph_semaphore_post(phdata, phdata->alife);
		ph_semaphore_close(phdata);
		while (1)
			usleep(1000000);
	}
	ph_semaphore_post(phdata, phdata->speeking);
}
