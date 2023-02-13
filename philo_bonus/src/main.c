/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:58:05 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/13 10:31:05 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_phdata	phdata;

	if (argc < 5 || argc > 6)
	{
		printf("Four or five arguments required\n");
		return (1);
	}
	ph_init_phdata(&phdata, argc, argv);
	ph_run_start(&phdata);
	ph_exit_error(&phdata, NULL);
	return (0);
}
