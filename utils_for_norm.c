/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_norm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:45:49 by nhill             #+#    #+#             */
/*   Updated: 2021/07/20 17:59:28 by nhill            ###   ########.fr       */
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
