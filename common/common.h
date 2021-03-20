/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 09:31:25 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/20 10:09:23 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <stdlib.h>
# include <unistd.h>
# include "../Libft/ft_printf/ft_printf.h"

typedef struct s_element
{
	struct s_element	*next;
	int					content;
}				t_element;

typedef struct s_stack
{
	t_element	*top;
	t_element	*end;
}				t_stack;

t_element	*new_element(int content);
t_stack	*new_stack(void);
void	push_element(t_element *elem, t_stack *stack);
t_element	*pop_element(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse(t_stack *stack);
int		ft_isnumer(const char *str);
int	fill_stack(int argc, char **argv, t_stack *stack);
int	init_stacks(int argc, char **argv,\
			t_stack *stack_a, t_stack *stack_b);
void	free_stack(t_stack *stack);
void	print_stack(t_stack *stack_a, t_stack *stack_b);
void	read_input(t_stack *stack_a, t_stack *stack_b);

#endif
