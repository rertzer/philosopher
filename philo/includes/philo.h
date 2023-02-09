/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:37:47 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/09 11:29:39 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

/* define */
# define MSG_NB 12

struct	s_philo;

typedef struct s_phdata
{
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				timeover;
	long int		time_start;
	struct s_philo	*akademia;
	pthread_mutex_t	mutex_timeover;
	pthread_mutex_t	*ware;
}	t_phdata;

typedef struct s_philo
{
	int				number;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				must_eat;
	long int		last_meal;
	pthread_mutex_t	mutex_last_meal;
	pthread_t		pthread;
	t_phdata		*phdata;
}	t_philo;

/* main */
/* parsing */
int				ph_parsing_atoi(int *n, char *str);
int				ph_parsing_safeadd(int *a, int b);
/* run */
int				ph_run_start(t_phdata *phdata);
void			ph_run_join(t_phdata *phdata);
void			ph_run_trial(t_phdata *phdata);
/* philo */
void			*ph_philo_start(void *void_philo);
void			*ph_philo_soliloquy(t_philo *philo);
void			*ph_philo_quit(t_philo *philo, int i);
void			*ph_philo_symposium(t_philo *philo);
/* philo life */
int				ph_philo_thinking(t_philo *philo);
int				ph_philo_eating(t_philo *philo);
int				ph_philo_sleeping(t_philo *philo);
void			ph_philo_dying(t_philo *philo);
/* forks */
pthread_mutex_t	*ph_forks_first(t_philo *philo);
pthread_mutex_t	*ph_forks_second(t_philo *philo);
/* clock */
long int		ph_clock_timestamp(t_phdata *phdata);
void			ph_clock_down(t_phdata *phdata);
int				ph_clock_running(t_phdata *phdata);
/* init */
int				ph_init_phdata(t_phdata *phdata, int argc, char **argv);
int				ph_init_akademia(t_phdata *phdata);
int				ph_init_philo(t_phdata *phdata, int i, int think);
int				ph_init_ware(t_phdata *phdata);
/* return */
int				ph_return_error(t_phdata *phdata, int error);
char			*ph_return_msg(int error);
void			ph_return_putmsg(char *str);
/* utils */
int				ph_utils_printmsg(t_phdata *phdata, int nb, char *str);
#endif
