/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:44:47 by fgata-va          #+#    #+#             */
/*   Updated: 2021/05/05 21:20:32 by fgata-va         ###   ########.fr       */
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
