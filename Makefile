# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 17:38:46 by fgata-va          #+#    #+#              #
#    Updated: 2021/04/18 19:31:39 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS := -Wall -Werror -Wextra -I. -g3 -fsanitize=leak

COMMON = common/stack_manager.c common/check_args.c common/instructions.c\
		 common/utils_1.c common/utils_2.c common/check_instructions.c

BONUS_SRC = common/verbose_bonus.c common/check_flags_bonus.c

CHECKER_SRC = checker_src/checker.c checker_src/read_input.c checker_src/get-next-line.c

CHECKER = checker

PS_SRC = ps_src/push_swap.c ps_src/bubble_sort.c ps_src/insertion.c ps_src/ps_utils_1.c

PUSH_SWAP = push_swap

INCLUDE_LIBFT = -L ./Libft/ -lft

LIBFT = Libft/libft.a

CHECKER_OBJS = $(CHECKER_SRC:.c=.o)

PS_OBJS = $(PS_SRC:.c=.o)

OBJS = $(COMMON:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(LIBFT) $(OBJS) $(CHECKER_OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(BONUS_OBJS) $(OBJS) -o $(CHECKER) $(INCLUDE_LIBFT)

$(PUSH_SWAP): $(LIBFT) $(OBJS) $(PS_OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(PS_OBJS) $(OBJS) $(BONUS_OBJS) -o $(PUSH_SWAP) $(INCLUDE_LIBFT)

$(LIBFT):
	$(MAKE) -C Libft

clean:
	rm -rf $(CHECKER_OBJS)
	rm -rf $(OBJS)
	rm -rf $(PS_OBJS)
	rm -rf $(BONUS_OBJS)
	@$(MAKE) -C Libft clean

fclean: clean
	rm -rf $(CHECKER) $(CHECKER).dSYM
	rm -rf $(PUSH_SWAP) $(PUSH_SWAP).dSYM
	@$(MAKE) -C Libft fclean

re: fclean all

norm:
	@echo "			Norminette COMMON and BONUS section:\n"
	@norminette $(COMMON) $(BONUS_SRC) common/common.h common/common_bonus.h
	@echo "			Norminette CHECKER section:\n"
	@norminette $(CHECKER_SRC) checker_src/checker.h
	@echo "			Norminette PUSH_SWAP section:\n"
	@norminette $(PS_SRC) ps_src/push_swap.h
	@echo "			Norminette LIBFT section:\n"
	@norminette Libft/

.PHONY: all clean fclean re
