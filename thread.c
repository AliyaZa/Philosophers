/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:24:31 by nhill             #+#    #+#             */
/*   Updated: 2021/07/18 19:42:14 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	sleep(long time_await)
{
	long	current_time;
	long	period;
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
		printf("%ld ms %d is eating", get_time() - phil->start_time, phil->id;
	pthread_mutex_unlock(&phil->mutex->written);


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
