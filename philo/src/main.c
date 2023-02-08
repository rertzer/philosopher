/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:58:05 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/08 11:21:03 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int			error;
	t_phdata	phdata;

	if (argc < 5 || argc > 6)
	{
		ft_putendl_fd(ph_return_msg(10), 2);
		return (1);
	}
	error = ph_init_phdata(&phdata, argc, argv);
	if (error)
		return (ph_return_error(&phdata, error));
	error = ph_run_start(&phdata);
	ph_run_join(&phdata);
	return (ph_return_error(&phdata, error));
}
