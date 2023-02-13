/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:37:40 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/13 17:14:52 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*ph_semaphore_open(t_phdata *phdata, char *name, int size)
{
	sem_t	*sema;

	errno = 0;
	sema = sem_open(name, O_RDWR | O_CREAT | O_EXCL, 0644, (unsigned int) size);
	if (SEM_FAILED == sema)
	{
		if (EEXIST == errno)
		{
			if (-1 == sem_unlink(name))
				ph_exit_error(phdata, "sem_unlink error");
			return (ph_semaphore_open(phdata, name, size));
		}
		else
			ph_exit_error(phdata, "sem_open error");
	}
	return (sema);
}

void	ph_semaphore_wait(t_phdata *phdata, t_philo *philo, sem_t *sema)
{
	ph_clock_ontime(phdata, philo);
	if (-1 == sem_wait(sema))
		ph_exit_error(phdata, "sem_wait error");
}

void	ph_semaphore_post(t_phdata *phdata, t_philo *philo, sem_t *sema)
{
	ph_clock_ontime(phdata, philo);
	if (-1 == sem_post(sema))
		ph_exit_error(phdata, "sem_post error");
}

void	ph_semaphore_giveback(t_phdata *phdata, t_philo *philo)
{
	ph_semaphore_wait(phdata, philo, phdata->table);
	ph_semaphore_post(phdata, philo, phdata->ware);
	ph_semaphore_post(phdata, philo, phdata->ware);
	phdata->fork_nb += 2;
	ph_semaphore_post(phdata, philo, phdata->table);
}
