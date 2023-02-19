/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:26:21 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/19 12:55:46 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ph_utils_printmsg(t_phdata *phdata, char *str)
{
	ph_semaphore_wait(phdata, phdata->speeking);
	printf("%ld %d %s\n", ph_clock_timestamp(phdata), phdata->number, str);
	ph_semaphore_post(phdata, phdata->speeking);
}
