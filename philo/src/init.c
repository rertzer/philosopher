/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:09:29 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/08 11:03:15 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_init_phdata(t_phdata *phdata, int argc, char **argv)
{
	if (-1 == ph_parsing_atoi(&phdata->nb_of_philo, argv[1]))
		return (1);
	if (-1 == ph_parsing_atoi(&phdata->time_to_die, argv[2]))
		return (2);
	if (-1 == ph_parsing_atoi(&phdata->time_to_eat, argv[3]))
		return (3);
	if (-1 == ph_parsing_atoi(&phdata->time_to_sleep, argv[4]))
		return (4);
	if (6 == argc)
	{
		if (-1 == ph_parsing_atoi(&phdata->must_eat, argv[5]))
			return (5);
	}
	else
		phdata->must_eat = -1;
	phdata->timeover = phdata->nb_of_philo;
	if (pthread_mutex_init(phdata->mutex_timeover, NULL))
		return (6);
	phdata->time_start = 0;
	phdata->time_start = ph_clock_timestamp(phdata);
	if (ph_init_akademia(phdata))
		return (7);
	return (ph_init_ware(phdata));
}

int	ph_init_akademia(t_phdata *phdata)
{
	int	i;

	phdata->akademia = malloc(phdata, sizeof(t_philo) * phdata->nb_of_philo);
	if (NULL == phdata->akademia)
		return (1);
	i = -1;
	while (++i < phdata->nb_of_philo)
	{
		phdata->akademia[i].number = i + 1;
		phdata->akademia[i].must_eat = phdata->must_eat;
		phdata->akademia[i].time_to_die = phdata->time_to_die;
		phdata->akademia[i].time_to_eat = phdata-time_to_eat;
		phdata->akademia[i].pthread = 0;
		phdata->akademia[i].phdata = phdata;
	}
	return (0);
}

int	ph_init_ware(t_phdata *phdata)
{
	int	i;

	phdata->ware = malloc(sizeof(p_thread_mutex) * phdata->nb_of_philo);
	if (NULL = phdata->ware)
		return (8);
	i = - 1;
	while (++i < phdata->nb_of_philo)
	{
		if (pthread_mutex_init(phdata->ware[i], NULL))
			return (9);
	}
	return (0);
}
