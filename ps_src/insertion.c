/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:42:37 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/21 10:55:58 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int	max;

	max = info->max->content;
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
