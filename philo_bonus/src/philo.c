/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:58:56 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/15 16:53:33 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ph_philo_start(t_phdata *phdata, int i)
{
	free(phdata->akademia);
	phdata->akademia = NULL;
	ph_init_philo(phdata, i);
	if (pthread_create(&phdata->pthread, NULL, ph_philo_life_start, phdata))
		ph_exit_error(phdata, "pthread_create error");
	ph_philo_killer(phdata);
}

void	ph_philo_killer(t_phdata *phdata)
{
	int	must;

	ph_semaphore_wait(phdata, phdata->speeking);
	must = phdata->must_eat;
	ph_semaphore_post(phdata, phdata->speeking);
	while (0 != must)
	{
		ph_clock_ontime(phdata);
		usleep(100);
		ph_semaphore_wait(phdata, phdata->speeking);
		must = phdata->must_eat;
		ph_semaphore_post(phdata, phdata->speeking);
	}
	pthread_join(phdata->pthread, NULL);
}

void	*ph_philo_life_start(void *data)
{
	t_phdata	*phdata;

	phdata = (t_phdata *) data;
	if (1 == phdata->nb_of_philo)
		ph_philo_soliloquy(phdata);
	else
		ph_philo_symposium(phdata);
	return (NULL);
}

int	ph_philo_soliloquy(t_phdata *phdata)
{
	while (0 != phdata->must_eat)
	{
		ph_clock_ontime(phdata);
		usleep(100);
	}
	return (0);
}

int	ph_philo_symposium(t_phdata *phdata)
{
	while (0 != phdata->must_eat)
	{
		ph_philo_taking(phdata);
		if (ph_philo_eating(phdata))
			return (0);
		ph_philo_sleeping(phdata);
		ph_philo_thinking(phdata);
	}
	return (0);
}
