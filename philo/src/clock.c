/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:58:47 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/08 10:54:21 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ph_clock_timestamp(t_phdata *phdata)
{
	struct timeval	*tv;

	if (gettimeofday(tv, NULL))
		return (-1);
	return ((tv->tv_usec / 1000) - phdata->time_start);
}

void	ph_clock_down(t_phdata *phdata)
{
	pthread_mutex_lock(&phdata->mutex_timeover);
	if (timeover > 0)
		timeover--;
	pthread_mutex_unlock(&phdata->mutex_timeover);
}

int	ph_clock_running(t_phdata *phdata)
{
	int	running;

	running = 0;
	pthread_mutex_lock(&phdata->mutex_timeover);
	if (timeover != 0)
		running = 1;
	pthread_mutex_unlock(&phdata->mutex_timeover);
	return (running);
}
