/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:35:20 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/16 18:22:41 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ph_exit_kill_all(t_phdata *phdata, int philo_nb)
{
	int	i;

	i = -1;
	while (++i < philo_nb)
	{
		if (-1 == kill(phdata->akademia[i], SIGKILL))
			ph_exit_error(phdata, "kill error");
	}
}

void	ph_exit_error(t_phdata *phdata, char *msg)
{
	free(phdata->akademia);
	phdata->akademia = NULL;
	if (msg)
	{
		ph_utils_errormsg(phdata, msg);
		exit(1);
	}
	if (-1 != sem_close(phdata->ware))
		sem_unlink(WARE_NAME);
	if (-1 != sem_close(phdata->table))
		sem_unlink(TABLE_NAME);
	if (-1 != sem_close(phdata->speeking))
		sem_unlink(SPEEKING_NAME);
	if (-1 != sem_close(phdata->alife))
		sem_unlink(ALIFE_NAME);
}
