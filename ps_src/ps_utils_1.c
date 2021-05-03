/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:44:47 by fgata-va          #+#    #+#             */
/*   Updated: 2021/05/03 17:04:27 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*get_element(t_stack *stack, int pos)
{
	t_element	*element;
	int			i;

	i = 0;
	element = stack->top;
	while (element && i < pos)
	{
		element = element->next;
		i++;
	}
	return (element);
}

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

int	get_content(t_stack *stack, int pos)
{
	t_element	*current;
	int			i;

	i = 0;
	current = stack->top;
	while (current && i < pos)
	{
		current = current->next;
		i++;
	}
	if (!current)
		return (0);
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

int		find_spot(t_stack *stack, int content)
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
