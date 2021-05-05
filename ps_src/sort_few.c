/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:49:52 by fgata-va          #+#    #+#             */
/*   Updated: 2021/05/05 21:06:58 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	t_element	*greatest;
	t_element	*lowest;

	greatest = info->max;
	lowest = info->min;
	while (!(check_stack_order(stack_a)))
	{
		if (!greatest->next || greatest->next != lowest)
			instruction("sa", stack_a, stack_b, 1);
		else
			put_top(info->min_pos, info, 'a');
		update_info(info);
	}
}

void	sort_four_five(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	repeat_inst("pb", info, info->elements - 3);
	update_info(info);
	sort_three(stack_a, stack_b, info);
	update_info(info);
	while (stack_b->top)
	{
		put_top(find_spot(stack_a, stack_b->top->content), info, 'a');
		instruction("pa", stack_a, stack_b, 1);
		update_info(info);
	}
	update_info(info);
	put_top(info->min_pos, info, 'a');
}
