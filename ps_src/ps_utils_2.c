/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:08:29 by fgata-va          #+#    #+#             */
/*   Updated: 2021/05/05 21:29:29 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	repeat_inst(char *inst, t_info *info, int steps)
{
	while (steps)
	{
		instruction(inst, info->stack_a, info->stack_b, 1);
		steps--;
	}
}

void	put_top(int pos, t_info *info, int stack)
{
	char	inst[4];
	int		stack_len;

	if (stack == 'a')
		stack_len = info->elements;
	else
		stack_len = info->elements_b;
	inst[0] = 'r';
	inst[2] = 0;
	inst[3] = 0;
	if (pos <= (stack_len / 2))
	{
		inst[1] = stack;
		repeat_inst(inst, info, pos);
	}
	else
	{
		inst[1] = 'r';
		inst[2] = stack;
		repeat_inst(inst, info, (stack_len - pos));
	}
}

int	find_spot(t_stack *stack, int content)
{
	t_element	*current;
	t_element	*min;
	int			pos;

	if (!stack->top)
		return (0);
	min = find_lowest(stack);
	current = min;
	pos = get_position(stack, current->content);
	while (current->content < content)
	{
		pos++;
		current = current->next;
		if (!current)
		{
			pos = 0;
			current = stack->top;
		}
		if (current == min)
			break ;
	}
	return (pos);
}

int	find_spot_b(t_stack *stack, int content)
{
	t_element	*current;
	t_element	*max;
	int			pos;

	if (!stack->top)
		return (0);
	max = find_greatest(stack);
	current = max;
	pos = get_position(stack, current->content);
	while (current->content > content)
	{
		pos++;
		current = current->next;
		if (!current)
		{
			pos = 0;
			current = stack->top;
		}
		if (current == max)
			break ;
	}
	return (pos);
}

int	linear_function(int elements)
{
	int		y;
	float	m;

	m = (15 - 5) / (500 - 100);
	y = 0.025 * (elements - 100) + 5;
	return (y);
}
