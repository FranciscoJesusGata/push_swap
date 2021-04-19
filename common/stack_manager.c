/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:33:49 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/16 09:30:51 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_element	*new_element(int content)
{
	t_element	*new_element;

	new_element = malloc(sizeof(t_element));
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->end = NULL;
	return (stack);
}

int	init_stacks(int argc, char **argv, t_data *data)
{
	data->stack_a.top = NULL;
	data->stack_b.top = NULL;
	data->stack_a.end = NULL;
	data->stack_b.end = NULL;
	if (!(fill_stack(argc, argv, data)))
	{
		free_stack(&data->stack_a);
		free_stack(&data->stack_b);
		return (0);
	}
	return (1);
}

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
	stack->top = NULL;
	stack->end = NULL;
}

int	fill_stack(int argc, char **argv, t_data *data)
{
	int			i;
	int			start;
	long long	num;

	start = 1;
	i = argc - 1;
	while (start < argc && check_flags_bonus(argv, &start, data))
		start++;
	while (i >= start)
	{
		if (count_args(argv[i]) > 1)
		{
			if (!(ft_strlen(argv[i])) || !(multi_args(argv[i], data)))
				return (0);
		}
		else if ((check_args(argv[i], &data->stack_a, &num)))
			push_element(new_element(num), &data->stack_a);
		else
			return (0);
		i--;
	}
	if (!data->stack_a.top)
		return (0);
	return (1);
}
