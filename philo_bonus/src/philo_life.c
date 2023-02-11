/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:12:33 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/11 11:10:41 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_philo_thinking(t_phdata *phdata, t_philo *philo)
{
	ph_clock_ontime(phdata, philo);
	ph_utils_printmsg(phdata, philo->number, "is thinking");
	ph_clock_sleep(phdata->time_to_think);
}

void	ph_philo_eating(t_phdata *phdata, t_philo *philo)
{
	ph_clock_ontime(phdata, philo);
	ph_utils_printmsg(phdata, philo->number, "is eating");
	philo->last_meal = ph_clock_timestamp(phdata);
	ph_clock_sleep(philo->time_to_eat);
	if (philo->must_eat > 0)
		philo->must_eat--;
	if (philo->must_eat == 0)
	{
		ph_semaphore_post(phdata, phdata->ware);
		ph_semaphore_post(phdata, phdata->ware);
		exit(0);
	}
}

void	ph_philo_sleeping(t_phdata *phdata, t_philo *philo)
{
	ph_clock_ontime(phdata, philo);
	ph_utils_printmsg(phdata, philo->number, "is sleeping");
	ph_clock_sleep(philo->time_to_sleep);
}

void	ph_philo_dying(t_phdata *phdata, t_philo *philo)
{		
	printf("%ld %d died\n", ph_clock_timestamp(phdata), philo->number);
}
