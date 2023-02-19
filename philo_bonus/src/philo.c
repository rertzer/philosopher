/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:58:56 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/19 11:54:11 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ph_philo_start(t_phdata *phdata, int i)
{
	free(phdata->akademia);
	phdata->akademia = NULL;
	ph_init_philo(phdata, i);
	if (pthread_create(&phdata->pthread, NULL, ph_philo_life_start, phdata))
		ph_exit_hemlock(phdata, "pthread_create error");
	else if (0 != pthread_detach(phdata->pthread))
		ph_exit_hemlock(phdata, "pthread detach error");
	else
		ph_philo_killer(phdata);
}

void	ph_philo_killer(t_phdata *phdata)
{
	while (1)
	{
		ph_clock_ontime(phdata);
		usleep(100);
	}
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

void	ph_philo_soliloquy(t_phdata *phdata)
{
	while (1)
	{
		ph_clock_ontime(phdata);
		usleep(100);
	}
}

void	ph_philo_symposium(t_phdata *phdata)
{
	while (1)
	{
		ph_philo_taking(phdata);
		ph_philo_eating(phdata);
		ph_philo_sleeping(phdata);
		ph_philo_thinking(phdata);
	}
}
