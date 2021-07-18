/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:35:20 by nhill             #+#    #+#             */
/*   Updated: 2021/07/18 18:02:47 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		init(int argc, char **argv, t_main_task *main_task)
{
	main_task->args = (t_arg *)malloc(sizeof(t_arg));
	if (!main_task->args)
		return(fn_error("can not allocate memory for args"));
	main_task->args->died = 0;
	main_task->args->number_of_philosophers = fn_atoi(argv[1]);
	if (main_task->args->number_of_philosophers < 2 || main_task->args->number_of_philosophers > 200)
		return (fn_error("incorrect number of philosophers"));
	main_task->args->time_to_die = fn_atoi(argv[2]);
	main_task->args->time_to_eat = fn_atoi(argv[3]);
	main_task->args->time_to_sleep = fn_atoi(argv[4]);
	if (argc == 6)
		main_task->args->number_of_times_each_philosopher_must_eat = fn_atoi(argv[5]);
	else
		main_task->args->number_of_times_each_philosopher_must_eat = 0;
}
