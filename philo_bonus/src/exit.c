/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:35:20 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/19 13:09:27 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ph_exit_kill_all(t_phdata *phdata, int philo_nb)
{
	int	i;

	i = -1;
	while (++i < philo_nb)
		kill(phdata->akademia[i], SIGKILL);
}

void	ph_exit_error(t_phdata *phdata, char *msg)
{
	free(phdata->akademia);
	phdata->akademia = NULL;
	ph_exit_sema(phdata->ware, WARE_NAME);
	ph_exit_sema(phdata->table, TABLE_NAME);
	ph_exit_sema(phdata->speeking, SPEEKING_NAME);
	ph_exit_sema(phdata->alife, ALIFE_NAME);
	if (msg)
	{
		printf("%s\n", msg);
		exit(1);
	}
}

void	ph_exit_hemlock(t_phdata *phdata, char *msg)
{
	ph_semaphore_post(phdata, phdata->alife);
	ph_semaphore_close(phdata);
	printf("%s\n", msg);
	exit(1);
}

void	ph_exit_sema(sem_t *sema, char *name)
{
	if (NULL != sema)
	{
		if (-1 != sem_close(sema))
			sem_unlink(name);
	}
}

void	ph_exit_parsing(char *msg)
{
	if (msg)
		printf("%s\n", msg);
	exit(1);
}
