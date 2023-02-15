/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:12:33 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/15 18:17:51 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ph_philo_taking(t_phdata *phdata)
{
	ph_semaphore_wait(phdata, phdata->table);
	ph_semaphore_wait(phdata, phdata->ware);
	ph_utils_printmsg(phdata, "has taken a fork");
	ph_semaphore_wait(phdata, phdata->ware);
	ph_utils_printmsg(phdata, "has taken a fork");
	ph_semaphore_post(phdata, phdata->table);
}

void	ph_philo_thinking(t_phdata *phdata)
{
	ph_utils_printmsg(phdata, "is thinking");
	ph_clock_sleep(phdata, phdata->time_to_think);
}

void	ph_philo_eating(t_phdata *phdata)
{
	ph_utils_printmsg(phdata, "is eating");
	ph_semaphore_wait(phdata, phdata->speeking);
	phdata->last_meal = ph_clock_timestamp(phdata);
	ph_semaphore_post(phdata, phdata->speeking);
	ph_clock_sleep(phdata, phdata->time_to_eat);
	ph_semaphore_giveback(phdata);
	ph_semaphore_wait(phdata, phdata->speeking);
	if (phdata->must_eat > 0)
		phdata->must_eat--;
	if (phdata->must_eat == 0)
		exit(1);
	ph_semaphore_post(phdata, phdata->speeking);
}

void	ph_philo_sleeping(t_phdata *phdata)
{
	ph_utils_printmsg(phdata, "is sleeping");
	ph_clock_sleep(phdata, phdata->time_to_sleep);
}
