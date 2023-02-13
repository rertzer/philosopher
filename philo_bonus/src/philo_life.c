/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:12:33 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/13 17:14:15 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ph_philo_taking(t_phdata *phdata, t_philo *philo)
{
	while (usleep(100))
	{
		ph_semaphore_wait(phdata, philo, phdata->table);
		if (phdata->fork_nb > 1)
		{
			ph_semaphore_wait(phdata, philo, phdata->ware);
			ph_clock_ontime(phdata, philo);
			ph_utils_printmsg(phdata, philo->number, "has taken a fork");
			ph_semaphore_wait(phdata, philo, phdata->ware);
			ph_clock_ontime(phdata, philo);
			ph_utils_printmsg(phdata, philo->number, "has taken a fork");
			phdata->fork_nb -= 2;
			ph_semaphore_post(phdata, philo, phdata->table);
			break ;
		}
		ph_semaphore_post(phdata, philo, phdata->table);
		ph_clock_ontime(phdata, philo);
	}
}

void	ph_philo_thinking(t_phdata *phdata, t_philo *philo)
{
	ph_clock_ontime(phdata, philo);
	ph_utils_printmsg(phdata, philo->number, "is thinking");
	ph_clock_sleep(phdata, philo, phdata->time_to_think);
}

void	ph_philo_eating(t_phdata *phdata, t_philo *philo)
{
	ph_clock_ontime(phdata, philo);
	ph_utils_printmsg(phdata, philo->number, "is eating");
	philo->last_meal = ph_clock_timestamp(phdata);
	ph_clock_sleep(phdata, philo, phdata->time_to_eat);
	ph_semaphore_giveback(phdata, philo);
	if (philo->must_eat > 0)
		philo->must_eat--;
	if (philo->must_eat == 0)
		exit(0);
}

void	ph_philo_sleeping(t_phdata *phdata, t_philo *philo)
{
	ph_clock_ontime(phdata, philo);
	ph_utils_printmsg(phdata, philo->number, "is sleeping");
	ph_clock_sleep(phdata, philo, phdata->time_to_sleep);
}

void	ph_philo_dying(t_phdata *phdata, t_philo *philo)
{		
	printf("%ld %d died\n", ph_clock_timestamp(phdata), philo->number);
}
