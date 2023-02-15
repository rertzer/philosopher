/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:39:29 by rertzer           #+#    #+#             */
/*   Updated: 2023/02/15 18:30:30 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <signal.h>
# include <semaphore.h>
# include <pthread.h>
# include <errno.h>
# include <fcntl.h>

/* define */
# define MSG_NB 12
# define WARE_NAME	"silverware"
# define TABLE_NAME "roundtable"
# define SPEEKING_NAME "herald"

typedef struct s_phdata
{
	long int	time_start;
	int			nb_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			time_to_think;
	int			must_eat;
	int			fork_nb;
	int			number;
	long int	last_meal;
	sem_t		*ware;
	sem_t		*table;
	sem_t		*speeking;
	pid_t		*akademia;
	pthread_t	pthread;

}	t_phdata;

/* main */
/* parsing */
int			ph_parsing_atoi(t_phdata *phdata, char *str);
int			ph_parsing_safeadd(t_phdata *phdata, int a, int b);
/* run */
void		ph_run_start(t_phdata *phdata);
void		ph_run_killer(t_phdata *phdata);
/* philo */
void		ph_philo_start(t_phdata *phdata, int i);
void		ph_philo_killer(t_phdata *phdata);
void		*ph_philo_life_start(void *data);
void		ph_philo_soliloquy(t_phdata *phdata);
void		ph_philo_symposium(t_phdata *phdata);
/* philo life */
void		ph_philo_taking(t_phdata *phdata);
void		ph_philo_thinking(t_phdata *phdata);
void		ph_philo_eating(t_phdata *phdata);
void		ph_philo_sleeping(t_phdata *phdata);
/* semaphore */
sem_t		*ph_semaphore_open(t_phdata *phdata, char *name, int size);
void		ph_semaphore_wait(t_phdata *phdata, sem_t *sema);
void		ph_semaphore_post(t_phdata *phdata, sem_t *sema);
void		ph_semaphore_giveback(t_phdata *phdata);
/* clock */
long int	ph_clock_timestamp(t_phdata *phdata);
void		ph_clock_sleep(t_phdata *phdata, int sleep_time);
void		ph_clock_ontime(t_phdata *phdata);
/* init */
void		ph_init_phdata(t_phdata *phdata, int argc, char **argv);
void		ph_init_semaphores(t_phdata *phdata);
void		ph_init_akademia(t_phdata *phdata);
void		ph_init_philo(t_phdata *phdata, int i);
/* exit */
void		ph_exit_error(t_phdata *phdata, char *msg);
void		ph_exit_kill_all(t_phdata *phdata, int philo_nb, pid_t pid);
/* utils */
void		ph_utils_printmsg(t_phdata *phdata, char *str);
void		ph_utils_errormsg(t_phdata *phdata, char *str);
#endif
