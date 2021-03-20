# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 17:38:46 by fgata-va          #+#    #+#              #
#    Updated: 2021/03/20 09:34:57 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS := -Wall -Werror -Wextra -I. -g

COMMON = common/basic_functions.c common/check_args.c common/instructions.c\
		 common/read_input.c common/verbose_bonus.c

CHECKER_SRC = checker.c

CHECKER = checker

PUSH_SWAP = push_swap

INCLUDE_LIBFT = -L ./Libft/ -lft

LIBFT = Libft/libft.a

CHECKER_OBJS = $(CHECKER_SRC:.c=.o)

OBJS = $(COMMON:.c=.o)

all: $(CHECKER)

$(CHECKER): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -c $(CHECKER_SRC)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(OBJS) -o $(CHECKER) $(INCLUDE_LIBFT)

$(LIBFT):
	$(MAKE) -C Libft

clean:
	rm -rf $(CHECKER_OBJS) $(OBJS)
	$(MAKE) -C Libft clean

fclean: clean
	rm -rf $(CHECKER) $(CHECKER).dSYM
	$(MAKE) -C Libft fclean

re: fclean all

norm:
	norminette $(CHECKER_SRC) *.h
	norminette Libft/

.PHONY: all clean fclean re
