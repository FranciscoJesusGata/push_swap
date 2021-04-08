/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:49:01 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/07 15:59:02 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	steps;
	int	i;
	int	j;

	i = 0;
	steps = ft_stack_len(stack_a);
	while (i < steps && !(check_stack_order(stack_a)))
	{
		j = 0;
		while (j < steps - 1)
		{
			if (stack_a->top->content > stack_a->top->next->content)
				instruction("sa", stack_a, stack_b, 1);
			instruction("ra", stack_a, stack_b, 1);
			j++;
		}
		instruction("ra", stack_a, stack_b, 1);
		i++;
	}
}
