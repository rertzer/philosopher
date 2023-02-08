/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:26:21 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/08 11:27:30 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_utils_printmsg(t_phdata *phdata, int nb, char *str)
{
	int	timer;

	pthread_mutex_lock(phdata->mutex_timeover);
	timer = phdata->timeover;
	if (timer)
		printf("%ld %d %s\n", ph_clock_timestamp(phdata), nb, str);
	pthread_mutex_unlock(phdata->mutex_timeover);
	return (timer);
}
