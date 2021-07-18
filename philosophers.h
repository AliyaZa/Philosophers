/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:05:22 by nhill             #+#    #+#             */
/*   Updated: 2021/07/18 17:42:46 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct		s_mutex
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	written;
	//pthread_mutex_t	*forks;
}					t_mutex;

typedef struct		s_arg
{
	long	number_of_philosophers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	number_of_times_each_philosopher_must_eat;
	int		died;
}					t_arg;

typedef struct		s_philosopher
{
	int				id;
	long			start_time;
	long			last_time;
	t_mutex			*mutex;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	pthread_t		philosopher;
}					t_philosopher;

typedef struct		s_main_task
{
	long			time;
	t_arg			*args;
	t_mutex			*mutexes;
	t_philosopher	*philosophers;
}					t_main_task;

int		fn_error(char *str);
int		fn_isdigit(int ch);
int		init(int argc, char **argv, t_main_task *main_task);

#endif
