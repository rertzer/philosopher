/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:58:47 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/15 15:12:04 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long int	ph_clock_timestamp(t_phdata *phdata)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		ph_exit_error(phdata, "clock error");
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - phdata->time_start);
}

void	ph_clock_sleep(t_phdata *phdata, int sleep_time)
{
	long int	start;
	long int	end;

	start = ph_clock_timestamp(phdata);
	end = start + sleep_time;
	while (ph_clock_timestamp(phdata) < end)
	{
		usleep(100);
		ph_clock_ontime(phdata);
	}
}

void	ph_clock_ontime(t_phdata *phdata)
{
	if (-1 == sem_wait(phdata->speeking))
		ph_exit_error(phdata, "sem_wait error");
	if (ph_clock_timestamp(phdata) > phdata->last_meal + phdata->time_to_die)
	{
		printf("%ld %d died\n", ph_clock_timestamp(phdata), phdata->number);
		exit(1);
	}
	if (-1 == sem_post(phdata->speeking))
		ph_exit_error(phdata, "sem_post error");
}
