/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:47:03 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/09 10:37:10 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_run_start(t_phdata *phdata)
{
	int	i;

	i = 0;
	while (i < phdata->nb_of_philo)
	{
		if (pthread_create(&phdata->akademia[i].pthread, NULL, ph_philo_start, \
					(void *)&phdata->akademia[i]))
			return (11);
		i += 2;
	}
	usleep(50);
	i = 1;
	while (i < phdata->nb_of_philo)
	{
		if (pthread_create(&phdata->akademia[i].pthread, NULL, ph_philo_start, \
					(void *)&phdata->akademia[i]))
			return (11);
		i += 2;
	}
	ph_run_trial(phdata);
	return (0);
}

void	ph_run_trial(t_phdata *phdata)
{
	int			i;
	long int	hungry;

	i = 0;
	while (ph_clock_running(phdata))
	{
		pthread_mutex_lock(&phdata->akademia[i].mutex_last_meal);
		hungry = ph_clock_timestamp(phdata) - phdata->akademia[i].last_meal;
		pthread_mutex_unlock(&phdata->akademia[i].mutex_last_meal);
		if (hungry > (long int) phdata->time_to_die)
		{
			ph_philo_dying(&phdata->akademia[i]);
			break ;
		}
		i = (i + 1) % phdata->nb_of_philo;
	}
}

void	ph_run_join(t_phdata *phdata)
{
	int	i;

	i = -1;
	while (++i < phdata->nb_of_philo)
		pthread_join(phdata->akademia[i].pthread, NULL);
}
