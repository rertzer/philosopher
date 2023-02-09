/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:58:56 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/09 10:41:57 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ph_philo_start(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (-1 == philo->time_to_think)
		return (ph_philo_soliloquy(philo));
	return (ph_philo_symposium(philo));
}

void	*ph_philo_soliloquy(t_philo *philo)
{
	while (ph_clock_running(philo->phdata))
		usleep(100);
	return (NULL);
}

void	*ph_philo_quit(t_philo *philo, int i)
{
	if (i == 2)
		pthread_mutex_unlock(ph_forks_second(philo));
	pthread_mutex_unlock(ph_forks_first(philo));
	return (NULL);
}

void	*ph_philo_symposium(t_philo *philo)
{
	while (ph_clock_running(philo->phdata))
	{
		pthread_mutex_lock(ph_forks_first(philo));
		if (ph_utils_printmsg(philo->phdata, philo->number, "has taken a fork"))
			return (ph_philo_quit(philo, 1));
		pthread_mutex_lock(ph_forks_second(philo));
		if (ph_utils_printmsg(philo->phdata, philo->number, "has taken a fork"))
			return (ph_philo_quit(philo, 2));
		if (ph_philo_eating(philo))
			return (ph_philo_quit(philo, 2));
		pthread_mutex_unlock(ph_forks_second(philo));
		pthread_mutex_unlock(ph_forks_first(philo));
		if (ph_philo_sleeping(philo))
			return (NULL);
		if (ph_philo_thinking(philo))
			return (NULL);
	}
	return (NULL);
}
