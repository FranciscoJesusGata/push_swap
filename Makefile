# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 17:38:46 by fgata-va          #+#    #+#              #
#    Updated: 2021/03/11 18:25:26 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS := -Wall -Werror -Wextra -I. -g

CHECKER_SRC = checker.c

CHECKER = checker

PUSH_SWAP = push_swap

CHECKER_OBJS = $(CHECKER_SRC:.o=.c)

all: $(CHECKER)

$(CHECKER):
	$(CC) $(CFLAGS) -c $(CHECKER_SRC)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER)

clean:
	rm -rf $(CHECKER_OBJS)

fclean:
	rm -rf $(CHECKER) $(CHECKER).dSYM

re: fclean all

.PHONY: all clean fclean re
