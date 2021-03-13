# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 17:38:46 by fgata-va          #+#    #+#              #
#    Updated: 2021/03/13 12:48:41 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS := -Wall -Werror -Wextra -I. -g

CHECKER_SRC = checker.c

CHECKER = checker

PUSH_SWAP = push_swap

LIBFT = -LLibft -lft

CHECKER_OBJS = $(CHECKER_SRC:.c=.o)

all: $(CHECKER)

$(CHECKER): libft
	$(CC) $(CFLAGS) -c $(CHECKER_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER)

clean:
	rm -rf $(CHECKER_OBJS)
	$(MAKE) -C Libft clean

fclean: clean
	rm -rf $(CHECKER) $(CHECKER).dSYM
	$(MAKE) -C Libft fclean

re: fclean all

libft:
	$(MAKE) -C Libft

norm:
	norminette $(CHECKER_SRC) *.h
	norminette Libft/

.PHONY: all clean fclean re
