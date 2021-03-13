/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:33:49 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/13 13:23:30 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_objects.h"

t_element	*new_element(int content)
{
	t_element	*new_element;

	new_element = malloc(sizeof(t_element));
	new_element->content = content;
	new_element->next = NULL;
}

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack->top = NULL;
	stack->end = NULL;
}

void	push_element(t_element *elem, t_stack *stack)
{
	elem->next = stack->top;
	stack->top = elem;
	if (!stack->end)
	{
		stack->end = elem;
	}
}

t_element	*pop_element(t_stack *stack)
{
	t_element *elem;

	elem = stack->top;
	stack->top = elem->next;
	return (elem);
}
