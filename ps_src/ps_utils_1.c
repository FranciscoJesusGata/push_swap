/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:44:47 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/22 11:18:02 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_stack *stack, int content)
{
	t_element	*current;
	int			pos;

	pos = 0;
	current = stack->top;
	while (current->content != content)
	{
		current = current->next;
		pos++;
	}
	return (pos);
}

t_element	*find_greatest(t_stack *stack)
{
	t_element	*current;
	t_element	*greatest;

	current = stack->top;
	greatest = current;
	while (current)
	{
		if (greatest->content < current->content)
			greatest = current;
		current = current->next;
	}
	return (greatest);
}

t_element	*find_lowest(t_stack *stack)
{
	t_element	*current;
	t_element	*lowest;

	current = stack->top;
	lowest = current;
	while (current)
	{
		if (lowest->content > current->content)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}

void	put_top(int pos, int stack_len, t_stack *a, t_stack *b)
{
	int		middle;
	char	*inst;
	int		steps;

	middle = stack_len / 2;
	if (pos <= middle)
	{
		inst = "ra";
		steps = pos;
	}
	else
	{
		inst = "rra";
		steps = stack_len - pos;
	}
	while (steps)
	{
		instruction(inst, a, b, 1);
		steps--;
	}
}
