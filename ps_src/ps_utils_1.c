/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:44:47 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/19 10:00:46 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_content(t_stack *stack, int pos)
{
	t_element *current;

	current = stack->top;
	while (pos)
	{
		current = current->next;
		pos--;
	}
	return (current->content);
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

void	put_top(int pos, int stack_len, t_stack *a, t_stack *b)
{
	int		middle;
	char	*inst;
	int		steps;

	middle = stack_len / 2;
	ft_printf("pos: %d, middle: %d, stack_len: %d\n", pos, middle, stack_len);
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
