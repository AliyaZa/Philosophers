/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:41:38 by nhill             #+#    #+#             */
/*   Updated: 2021/07/18 17:42:44 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		check_word(char *word)
{
	int	i;

	i = 0;
	while (word[i])
	{
		if (!fn_isdigit(word[i]))
			return (fn_error("not a valid argument"));
	}
	return (0);
}

int		check_args(char **argv)
{
	int	i;

	i = 1;
	while(argv[i++])
	{
		if (check_word(argv[i]))
			return (1);
	}
	return(0);
}



int		main(int argc, char **argv)
{
	t_main_task	main_task;
	if (argc < 5 || argc > 6)
		return (fn_error("Wrong number of arguments"));
	if (check_args(argv))
		return (1);
	if (init(argc, argv, &main_task))
		return (1);
	return (0);
}
