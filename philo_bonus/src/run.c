/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:47:03 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/16 18:55:04 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ph_run_start(t_phdata *phdata)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (++i < phdata->nb_of_philo)
	{
		pid = fork();
		if (-1 == pid)
		{
			ph_exit_kill_all(phdata, i);
			ph_exit_error(phdata, "fork error");
		}
		else if (0 == pid)
			ph_philo_start(phdata, i);
		else
			phdata->akademia[i] = pid;
	}
	ph_run_killer(phdata);
}

void	ph_run_killer(t_phdata *phdata)
{
	int	i;

	ph_semaphore_wait(phdata, phdata->alife);
	ph_exit_kill_all(phdata, phdata->nb_of_philo);
	i = -1;
	while (++i < phdata->nb_of_philo)
	{
		waitpid(-1, NULL, 0);
	}
}
