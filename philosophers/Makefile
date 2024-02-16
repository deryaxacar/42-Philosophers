# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 12:59:23 by deryacar          #+#    #+#              #
#    Updated: 2024/02/15 17:39:02 by deryacar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c init.c launcher.c utils.c utils2.c controls.c

OBJS	= $(SRCS:.c=.o)
NAME	= philo
GCC	= gcc
FLAGS	= -Wall -Wextra -Werror #-fsanitize=thread -g
INCLUDE	= -lpthread
HEADER	= philo.h

all:	$(NAME)

$(NAME): $(OBJS)
	$(GCC) $(INCLUDE) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "\033[1;32mFiles compiled successfully ✅\033[0m\n"

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)
	@echo "\033[1;32mFiles deleted ✅\033[0m\n"

re: fclean all

%.o: %.c $(HEADER)
	$(GCC) $(FLAGS) -c $<  -o $(<:.c=.o)

.PHONY:	clean fclean re bonus bench bclean