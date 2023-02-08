/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:47:03 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/08 11:28:30 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_run_start(t_phdata *phdata)
{
	int	i;

	i = -1;
	while (++i < phdata->number_of_philosophers)
	{
		if (pthread_create(phdata->akademia[i].pthread, NULL, ph_philo_start, phdata->akademia[i]))
			return (11) ;
	}
	ph_run_trial(phdata);
}

void	ph_run_trial(t_phdata *phdata)
{
	int	i;

	i = 0;
	while (ph_clock_running(phdata))
	{
		if (ph_clock_timestamp() - phdata->akademia[i].last_meal > phdata->time_to_die)
		{
			ph_philo_dying(phdata->philo[i]);
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
		pthread_join(phdata->akademia[i]->pthread);
}
