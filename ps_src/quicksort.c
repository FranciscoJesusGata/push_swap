/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 12:53:24 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/26 12:35:41 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../common/common_bonus.h"

t_pivot	createPivot(int pos, t_stack *stack)
{
	t_pivot new;

	new.pos = pos;
	new.element = get_element(stack, pos);
	new.sorted = 0;
	return (new);
}

void	position_pivot(t_info *info, t_stack *stack_a, t_stack *stack_b, t_pivot *pivot)
{
	t_element	*current;
	int			pos;

	pos = 0;
	current = stack_a->top;
	while (current)
	{
		if (current->content < pivot->element->content)
		{
			put_top(pos, info->elements, stack_a, stack_b);
			instruction("pb", stack_a, stack_b, 1);
			update_info(info);
			current = stack_a->top;
			pos = 0;
		}
		pos++;
		current = current->next;
	}
	pivot->pos = get_position(stack_a, pivot->element->content);
	put_top(pivot->pos, info->elements, stack_a, stack_b);
	while (stack_b->top)
		instruction("pa", stack_a, stack_b, 1);

}

void	quicksort(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	t_pivot		pivot;

	pivot = createPivot((info->elements / 2), stack_a);
	position_pivot(info, stack_a, stack_b, &pivot);
	pivot.pos = get_position(stack_a, pivot.element->content);
	print_stack_bonus(stack_a, stack_b, info->elements);
}
