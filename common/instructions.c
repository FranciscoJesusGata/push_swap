/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:06:44 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/16 16:22:33 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	swap(t_stack *stack)
{
	t_element *aux;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	aux = stack->top;
	stack->top = aux->next;
	aux->next = stack->top->next;
	stack->top->next = aux;
}

void	push_element(t_element *elem, t_stack *stack)
{
	if (elem)
	{
		elem->next = stack->top;
		stack->top = elem;
		if (!stack->end)
			stack->end = elem;
	}
}

t_element	*pop_element(t_stack *stack)
{
	t_element *elem;

	if (!stack || !stack->top)
		return (NULL);
	elem = stack->top;
	elem->next = NULL;
	stack->top = elem->next;
	return (elem);
}

void	rotate(t_stack *stack)
{
	t_element	*top;

	top = pop_element(stack);
	stack->end->next = top;
	stack->end = top;
}

void	reverse(t_stack *stack)
{
	t_element	*current;

	current = stack->top;
	while (current->next != stack->end)
		current = current->next;
	stack->end->next = stack->top;
	stack->top = stack->end;
	stack->end = current;
	current->next = NULL;
}

