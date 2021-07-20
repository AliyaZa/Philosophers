/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:51:05 by nhill             #+#    #+#             */
/*   Updated: 2021/07/20 17:51:48 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	fn_isspace(int c)
{
	if (c && ((c == 32) || ((c >= 9) && (c <= 13))))
		return (1);
	return (0);
}

int	fn_atoi(const char *str)
{
	unsigned int	ch;
	unsigned int	l_ch;
	int				i;
	int				zn;

	ch = 0;
	i = 0;
	zn = 1;
	while (str[i] && (fn_isspace(str[i])))
		i++;
	proverka(str, &i, &zn);
	while (str[i] >= '0' && str[i] <= '9')
	{
		l_ch = ch;
		ch = ch * 10 + (unsigned int)(str[i++] - '0');
		if (l_ch > ch)
		{
			if (zn > 0)
				return (-1);
			else
				return (0);
		}
	}
	return (ch * zn);
}

static int	fn_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	fn_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	else
		return (0);
}

int	fn_error(char *str)
{
	write(2, "Error: ", 7);
	write(2, str, fn_strlen(str));
	write(2, "\n", 1);
	return (1);
}
