/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:26:21 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/08 15:32:45 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_utils_printmsg(t_phdata *phdata, int nb, char *str)
{
	int	timer;

	pthread_mutex_lock(&phdata->mutex_timeover);
	timer = phdata->timeover;
	if (timer)
		printf("%ld %d %s\n", ph_clock_timestamp(phdata), nb, str);
	pthread_mutex_unlock(&phdata->mutex_timeover);
	return (timer == 0);
}
