/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:24:31 by nhill             #+#    #+#             */
/*   Updated: 2021/07/20 16:33:40 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	sleep(long time_await)
{
	long	current_time;
	long	period;

	current_time = get_time();
	period = current_time + time_await;
	while (period > current_time)
	{
		usleep(1);
		current_time = get_time();
	}
}

void	phil_eat(t_philosopher *phil)
{
	pthread_mutex_lock(phil->left_fork);
	pthread_mutex_lock(phil->right_fork);
	pthread_mutex_lock(&phil->mutex->written);
	if (phil->args->died ==0)
		printf("%ld ms %d has taken a forks\n", get_time() - phil->start_time, phil->id);
	phil->last_time = get_time() - phil->start_time;
	if (phil->args->died == 0)
		printf("%ld ms %d is eating", get_time() - phil->start_time, phil->id);
	pthread_mutex_unlock(&phil->mutex->written);
	sleep(phil->args->time_to_eat);
	pthread_mutex_unlock(phil->left_fork);
	pthread_mutex_unlock(phil->right_fork);
}

void	*check_death(void *philosopher)
{
	t_philosopher	*phil;

	phil = (t_philosopher *)philosopher;
	while (!phil->args->died)
	{
		if ((get_time() - phil->start_time - phil->last_time) > phil->args->time_to_die)
		{
			pthread_mutex_lock(&phil->mutex->written);
			if (phil->args->died == 0)
				printf("%ld ms %d died\n", get_time() - phil->start_time, phil->id);
			phil->args->died = 1;
			pthread_mutex_unlock(&phil->mutex->written);
		}
	}
	return (NULL);
}

int	phil_full(t_philosopher *phil, int *i)
{
	if (phil->args->number_of_times_each_philosopher_must_eat > 0)
	{
		(*i)++;
		if (*i == phil->args->number_of_times_each_philosopher_must_eat)
		{
			if (phil->args->died == 0)
			{
				pthread_mutex_lock(&phil->mutex->written);
				printf("%ld ms %d is full\n", get_time() - phil->start_time, phil->id);
				pthread_mutex_unlock(&phil->mutex->written);
				return (1);
			}
		}
	}
}
