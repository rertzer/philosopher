/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:58:56 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/13 17:07:03 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ph_philo_start(t_phdata *phdata, int i)
{
	t_philo	philo;

	free(phdata->akademia);
	ph_init_philo(phdata, &philo, i);
	if (1 == phdata->nb_of_philo)
		ph_philo_soliloquy(phdata, &philo);
	else
		ph_philo_symposium(phdata, &philo);
}

void	ph_philo_soliloquy(t_phdata *phdata, t_philo *philo)
{
	while (0 != phdata->must_eat)
	{
		ph_clock_ontime(phdata, philo);
		usleep(100);
	}
	exit(0);
}

void	ph_philo_symposium(t_phdata *phdata, t_philo *philo)
{
	while (0 != philo->must_eat)
	{
		ph_philo_taking(phdata, philo);
		ph_clock_ontime(phdata, philo);
		ph_philo_eating(phdata, philo);
		ph_clock_ontime(phdata, philo);
		ph_philo_sleeping(phdata, philo);
		ph_clock_ontime(phdata, philo);
		ph_philo_thinking(phdata, philo);
		ph_clock_ontime(phdata, philo);
	}
	exit(0);
}
