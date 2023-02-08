/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:37:42 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/06 13:51:40 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*ph_forks_first(t_philo *philo)
{
	int	fork_index;
	
	if (philo->number % 2)
		fork_index = philo->number % philo->phdata->nb_of_philo;
	else
		fork_index = philo->number - 1;
	return (philo->phdata->ware[fork_index]);
}

pthread_mutex_t	*ph_forks_second(t_philo *philo)
{
	int	fork_index;
	
	if (philo->number % 2)
		fork_index = philo->number - 1;
	else
		fork_index = philo->number % philo->phdata->nb_of_philo;
	return (philo->phdata->ware[fork_index]);
}
