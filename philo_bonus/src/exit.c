/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:35:20 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/15 18:37:37 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ph_exit_kill_all(t_phdata *phdata, int philo_nb, pid_t pid)
{
	int	i;

	i = -1;
	while (++i < philo_nb)
	{
		if (pid == phdata->akademia[i])
			continue ;
		if (-1 == kill(phdata->akademia[i], SIGTERM))
			ph_exit_error(phdata, "kill error");
	}
	i = -1;
	while (++i < philo_nb)
		waitpid(-1, NULL, 0);
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
}
