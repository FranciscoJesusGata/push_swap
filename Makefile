# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 17:38:46 by fgata-va          #+#    #+#              #
#    Updated: 2021/03/29 13:22:22 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS := -Wall -Werror -Wextra -I. -g

COMMON = common/basic_functions.c common/check_args.c common/instructions.c\
		 common/get-next-line.c common/utils_1.c common/verbose_bonus.c

CHECKER_SRC = checker_src/checker.c checker_src/read_input.c

CHECKER = checker

PS_SRC = ps_src/push_swap.c ps_src/bubble_sort.c

PUSH_SWAP = push_swap

INCLUDE_LIBFT = -L ./Libft/ -lft

LIBFT = Libft/libft.a

CHECKER_OBJS = $(CHECKER_SRC:.c=.o)

PS_OBJS = $(PS_SRC:.c=.o)

OBJS = $(COMMON:.c=.o)

all: $(CHECKER) $(PUSH_SWAP)

bonus: $(CHECKER)

$(CHECKER): $(LIBFT) $(OBJS) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(OBJS) -o $(CHECKER) $(INCLUDE_LIBFT)

$(PUSH_SWAP): $(LIBFT) $(OBJS) $(PS_OBJS)
	$(CC) $(CFLAGS) $(PS_OBJS) $(OBJS) -o $(PUSH_SWAP) $(INCLUDE_LIBFT)

$(LIBFT):
	$(MAKE) -C Libft

clean:
	rm -rf $(CHECKER_OBJS)
	rm -rf $(OBJS)
	rm -rf $(PS_OBJS)
	@$(MAKE) -C Libft clean

fclean: clean
	rm -rf $(CHECKER) $(CHECKER).dSYM
	@$(MAKE) -C Libft fclean

re: fclean all

norm:
	norminette $(CHECKER_SRC) $(COMMON) $(PS_SRC) push_swap/push_swap.h \
	checker/checker.h common/common.h
	norminette Libft/

.PHONY: all clean fclean re
