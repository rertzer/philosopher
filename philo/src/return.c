/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:41:50 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/08 11:39:38 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_return_error(t_phdata *phdata, int error)
{
	int	i;

	if (error)
		ph_return_putmsg(ph_return_msg(error));
	i = -1;
	while (i++ < phdata->nb_of_philo)
		pthread_mutex_destroy(phdata->ware[i]);
	pthread_mutex_destroy(phdata->mutex_timeover);
	free(phdata->akademia);
	free(phdata->ware);
	return (error);
}

char	*ph_return_msg(int error)
{
	char	*msg[MSG_NB];

	if (error > MSG_NB || < 0)
		error = MSG_NB;
	msg[0] = "";
	msg[1] = "Error: first argument invalid";
	msg[2] = "Error: second argument invalid";
	msg[3] = "Error: third argument invalid";
	msg[4] = "Error: fourth argument invalid";
	msg[5] = "Error: fifth argument invalid";
	msg[6] = "Error: mutex init error";
	msg[7] = "Error: akademia malloc error";
	msg[8] = "Error: ware malloc error";
	msg[9] = "Error: ware mutex error";
	msg[10] = "Error: five or six arguments required";
	msg[11] = "Error: pthread_init error";
	msg[12] = "Error";
	return (msg[error]);
}

void	ph_return_putmsg(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, str, len);
	write(2, "\n", 1);
}
}
