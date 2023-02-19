/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:37:40 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/19 12:47:25 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*ph_semaphore_open(t_phdata *phdata, char *name, int size)
{
	sem_t	*sema;

	sem_unlink(name);
	errno = 0;
	sema = sem_open(name, O_RDWR | O_CREAT, 0644, (unsigned int) size);
	if (SEM_FAILED == sema)
		ph_exit_error(phdata, "sem_open error");
	return (sema);
}

void	ph_semaphore_close(t_phdata *phdata)
{
	sem_close(phdata->ware);
	sem_close(phdata->table);
	sem_close(phdata->speeking);
	sem_close(phdata->alife);
}

void	ph_semaphore_wait(t_phdata *phdata, sem_t *sema)
{
	if (-1 == sem_wait(sema))
		ph_exit_hemlock(phdata, "sem_wait error");
}

void	ph_semaphore_post(t_phdata *phdata, sem_t *sema)
{
	if (-1 == sem_post(sema))
		ph_exit_hemlock(phdata, "sem_post error");
}

void	ph_semaphore_giveback(t_phdata *phdata)
{
	ph_semaphore_post(phdata, phdata->ware);
	ph_semaphore_post(phdata, phdata->ware);
}
