# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhill <nhill@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 19:49:45 by nhill             #+#    #+#              #
#    Updated: 2021/07/20 17:04:07 by nhill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror

CC = gcc

SRCS = main.c philo_utils.c init.c thread.c

HDR = ./

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS)
			$(CC) -g $(CFLAGS) -I$(HDR) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all re clean fclean
