/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:42:37 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/28 21:17:44 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_stack *stack_a, t_info *info)
{
	while (!(check_stack_order(stack_a)) && stack_a->top->next)
	{
		put_top(info->min_pos, info, 'a');
		if (!(check_stack_order(stack_a)))
			instruction("pb", info->stack_a, info->stack_b, 1);
		update_info(info);
	}
	repeat_inst("pa", info, info->elements_b);
}
