/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:33:49 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/20 13:20:23 by fgata-va         ###   ########.fr       */
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

int	init_stacks(int argc, char **argv,\
			t_stack *stack_a, t_stack *stack_b)
{
	stack_a->top = NULL;
	stack_b->top = NULL;
	stack_a->end = NULL;
	stack_b->end = NULL;
	if (!(fill_stack(argc, argv, stack_a)))
	{
		free_stack(stack_a);
		free_stack(stack_b);
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