/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:58:56 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/08 10:43:58 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ph_philo_start(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	philo->last_meal = ph_clock_timestamp(phdata);
	return (ph_philo_symposium(philo));
}

void	*ph_philo_symposium(t_philo *philo)
{
	while (ph_clock_running(philo->phdata))
	{
		pthread_mutex_lock(ph_forks_first(philo));
		if (ph_utils_printmsg(philo->phdata, philo->number, "has taken a fork"))
			return (NULL); 
		pthread_mutex_lock(ph_forks_second(philo));
		if (ph_utils_printmsg(philo->phdata, philo->number, "has taken a fork"))
			return (NULL); 
		if (ph_philo_eating(philo))
			return (NULL);
		pthread_mutex_unlock(ph_forks_second(philo));
		pthread_mutex_unlock(ph_forks_first(philo));
		if (ph_philo_sleeping(philo))
			return (NULL);
		if (ph_utils_printmsg(philo->phdata, philo->number, "is thinking"))
			return (NULL); 
	}	
	return (NULL);
}

int	ph_philo_eating(t_philo *philo)
{
	int	last_meal;

	last_meal = 0;
	if (ph_utils_printmsg(philo->phdata, philo->number, "is eating"))
		return (1);
	if (philo->must_eat > 0)
		philo->must_eat--;
	if (philo->must_eat == 0)
	{
		ph_clock_down(philo->phdata);
		last_meal = 1;
	}
	usleep(philo->time_to_eat * 1000);
	return (last_meal);
}

int	ph_philo_sleeping(t_philo *philo)
{
	if (ph_utils_printmsg(philo->phdata, philo->number, "is sleeping"))
		return (1);
	usleep(philo->time_to_sleep * 1000);
	return (0);
}

void	ph_philo_dying(t_philo *philo);
{		
	pthread_mutex_lock(philo->phdata->mutex_timeover);
	phdata->timeover = 0;
	printf("%ld %d %s died\n", ph_clock_timestamp(phdata), nb);
	pthread_mutex_unlock(philo->phdata->mutex_timeover);
}
