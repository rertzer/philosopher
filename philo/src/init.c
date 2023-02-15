/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:09:29 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/15 17:29:34 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_init_phdata(t_phdata *phdata, int argc, char **argv)
{
	memset(phdata, 0, sizeof(t_phdata));
	if (ph_parsing_atoi(&phdata->nb_of_philo, argv[1]))
		return (1);
	if (ph_parsing_atoi(&phdata->time_to_die, argv[2]))
		return (2);
	if (ph_parsing_atoi(&phdata->time_to_eat, argv[3]))
		return (3);
	if (ph_parsing_atoi(&phdata->time_to_sleep, argv[4]))
		return (4);
	if (6 == argc)
	{
		if (ph_parsing_atoi(&phdata->must_eat, argv[5]))
			return (5);
	}
	else
		phdata->must_eat = -1;
	return (ph_init_phdata_etc(phdata));
}

int	ph_init_phdata_etc(t_phdata *phdata)
{
	int	think;

	phdata->timeover = phdata->nb_of_philo;
	think = (phdata->time_to_die - \
			(phdata->time_to_eat + phdata->time_to_sleep)) / 2;
	if (think < 0)
		think = 0;
	if (1 == phdata->nb_of_philo)
		think = -1;
	phdata->time_to_think = think;
	if (pthread_mutex_init(&phdata->mutex_timeover, NULL))
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

	phdata->akademia = malloc(sizeof(t_philo) * phdata->nb_of_philo);
	if (NULL == phdata->akademia)
		return (1);
	i = -1;
	while (++i < phdata->nb_of_philo)
	{
		if (ph_init_philo(phdata, i))
			return (1);
	}
	return (0);
}

int	ph_init_philo(t_phdata *phdata, int i)
{
	phdata->akademia[i].number = i + 1;
	phdata->akademia[i].must_eat = phdata->must_eat;
	phdata->akademia[i].last_meal = ph_clock_timestamp(phdata);
	if (pthread_mutex_init(&phdata->akademia[i].mutex_last_meal, NULL))
		return (1);
	phdata->akademia[i].pthread = 0;
	phdata->akademia[i].phdata = phdata;
	return (0);
}

int	ph_init_ware(t_phdata *phdata)
{
	int	i;

	phdata->ware = malloc(sizeof(pthread_mutex_t) * phdata->nb_of_philo);
	if (NULL == phdata->ware)
		return (8);
	i = -1;
	while (++i < phdata->nb_of_philo)
	{
		if (pthread_mutex_init(&phdata->ware[i], NULL))
			return (9);
	}
	return (0);
}
