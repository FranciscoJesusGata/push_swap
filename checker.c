/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:16:10 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/18 10:28:14 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	free_stack(t_stack *stack)
{
	t_element	*current;
	t_element	*aux;

	current = stack->top;
	while (current)
	{
		aux = current->next;
		free(current);
		current = aux;
	}
	aux = NULL;
	free(stack);
	stack = NULL;
}

int		ft_isnumer(const char *str)
{
	while (str)
	{
		if(!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	fill_stack(int argc, char **argv, t_stack *stack)
{
	int	num;
	int	isNum;
	int	i;

	i = 1;
	num = 0;
	isNum = ft_isnumer(argv[i]);
	while (i < argc && isNum)
	{
		num = ft_atoi(argv[i]);
		push_element(new_element(num), stack);
		i++;
		isNum = ft_isnumer(argv[i]);
	}
	if (isNum)
		free_stack(stack);
	return (isNum);
}

int	init_stacks(int argc, char **argv,\
			t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !fill_stack(argc, argv, stack_a))
	{
		free(stack_b);
		return (0);
	}
	if (!stack_b)
	{
		free(stack_a);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	i = 1;
	if (argc == 1 || !init_stacks(argc, argv, stack_a, stack_b))
		return (1);
	return (0);
}
