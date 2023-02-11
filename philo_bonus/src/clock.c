/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:58:47 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/11 11:10:17 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ph_clock_timestamp(t_phdata *phdata)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		ph_exit_error(phdata, "clock error");
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - phdata->time_start);
}

void	ph_clock_sleep(t_phdata *phdata, t_philo *philo, int sleep_time)
{
	long int	start;
	long int	time;
	long int	end;

	start = ph_clock_timestamp(phdata);
	end = start + sleep_time;
	while (ph_clock_timestamp(phdata) < end)
	{
		usleep(100);
		ph_clock_ontime(phdata, philo);
	}
}

void	ph_clock_ontime(t_phdata *phdata, t_philo *philo)
{
	if (ph_clock_timestamp(phdata) > philo->last_meal + phdata->time_to_die)
	{
		if (-1 == sem_wait(phdata->speeking))
			ph_exit_error(phdata, "sem_wait error");
		printf("%ld %d died\n", ph_clock_timestamp(phdata), philo->number);
		exit(1);
	}
}
