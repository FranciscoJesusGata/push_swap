/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:49:01 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/29 13:51:34 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stack_len(t_stack *stack)
{
	t_element	*current;
	int			len;

	len = 0;
	current = stack->top;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

void	bubble_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	steps;
	int	i;

	i = 0;
	steps = ft_stack_len(stack_a);
	while (i < steps)
	{
		/*
		 ** Stuff to do here
		 */
		i++;
	}
	print_stack(stack_a, stack_b);
}
