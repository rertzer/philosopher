/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:26:21 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/13 10:42:59 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ph_utils_printmsg(t_phdata *phdata, int nb, char *str)
{
	if (-1 == sem_wait(phdata->speeking))
		ph_exit_error(phdata, "sem_wait error");
	printf("%ld %d %s\n", ph_clock_timestamp(phdata), nb, str);
	if (-1 == sem_post(phdata->speeking))
		ph_exit_error(phdata, "sem_post error");
}

void	ph_utils_errormsg(t_phdata *phdata, char *msg)
{
	if (-1 == sem_wait(phdata->speeking))
		ph_exit_error(phdata, "sem_wait error");
	printf("%s\n", msg);
	if (-1 == sem_post(phdata->speeking))
		ph_exit_error(phdata, "sem_post error");
}
