/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_norm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:45:49 by nhill             #+#    #+#             */
/*   Updated: 2021/07/25 20:08:41 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	proverka(const char *str, int *i, int *zn)
{
	if ((str[*i] == '+') || (str[*i] == '-'))
	{
		if (str[*i] == '-')
			(*zn) = -(*zn);
		(*i)++;
	}
}

void	fn_sleep(long time_await)
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

void	fn_death(t_main_task *main_task)
{
	t_philosopher	phil;

	phil = main_task->philosophers[0];
	while (!phil.args->died)
	{
		if ((get_time() - phil.start_time - phil.last_time)
			> phil.args->time_to_die)
		{
			pthread_mutex_lock(&phil.mutex->written);
			if (phil.args->died == 0)
				printf("%ld ms %d died\n", get_time()
					- phil.start_time, phil.id);
			phil.args->died = 1;
			pthread_mutex_unlock(&phil.mutex->written);
		}
	}
}
