/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:12:33 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/15 17:10:46 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_philo_thinking(t_philo *philo)
{
	if (ph_utils_printmsg(philo->phdata, philo->number, "is thinking"))
		return (1);
	usleep(philo->phdata->time_to_think * 1000);
	return (0);
}

int	ph_philo_eating(t_philo *philo)
{
	int	satiated;

	satiated = 0;
	if (ph_utils_printmsg(philo->phdata, philo->number, "is eating"))
		return (1);
	pthread_mutex_lock(&philo->mutex_last_meal);
	philo->last_meal = ph_clock_timestamp(philo->phdata);
	pthread_mutex_unlock(&philo->mutex_last_meal);
	if (philo->must_eat > 0)
		philo->must_eat--;
	if (philo->must_eat == 0)
	{
		ph_clock_down(philo->phdata);
		satiated = 1;
	}
	usleep(philo->phdata->time_to_eat * 1000);
	return (satiated);
}

int	ph_philo_sleeping(t_philo *philo)
{
	if (ph_utils_printmsg(philo->phdata, philo->number, "is sleeping"))
		return (1);
	usleep(philo->phdata->time_to_sleep * 1000);
	return (0);
}

void	ph_philo_dying(t_philo *philo)
{		
	pthread_mutex_lock(&philo->phdata->mutex_timeover);
	philo->phdata->timeover = 0;
	printf("%ld %d died\n", ph_clock_timestamp(philo->phdata), philo->number);
	pthread_mutex_unlock(&philo->phdata->mutex_timeover);
}
