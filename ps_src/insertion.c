/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:42:37 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/07 15:59:15 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_greatest(t_stack *stack)
{
	t_element	*current;
	int			greatest;

	current = stack->top;
	greatest = current->content;
	while (current)
	{
		if (greatest < current->content)
			greatest = current->content;
		current = current->next;
	}
	return (greatest);
}

void	insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max;

	max = find_greatest(stack_a);
	while (!(check_stack_order(stack_a) && !stack_b->top))
	{
		if (stack_b->top && stack_b->top->content < stack_a->top->content)
		{
			instruction("pa", stack_a, stack_b, 1);
		}
		else if (stack_a->top->content > stack_a->top->next->content \
			&& stack_a->top->content != max)
		{
			instruction("pb", stack_a, stack_b, 1);
		}
		instruction("ra", stack_a, stack_b, 1);
	}
}
