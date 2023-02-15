/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:37:40 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/15 13:57:32 by rertzer          ###   ########.fr       */
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

void	ph_semaphore_wait(t_phdata *phdata, sem_t *sema)
{
	if (-1 == sem_wait(sema))
		ph_exit_error(phdata, "sem_wait error");
}

void	ph_semaphore_post(t_phdata *phdata, sem_t *sema)
{
	if (-1 == sem_post(sema))
		ph_exit_error(phdata, "sem_post error");
}

void	ph_semaphore_giveback(t_phdata *phdata)
{
	ph_semaphore_post(phdata, phdata->ware);
	ph_semaphore_post(phdata, phdata->ware);
}
