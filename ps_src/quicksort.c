/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 12:53:24 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/25 12:30:25 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../common/common_bonus.h"

void	quicksort(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int			pivot;
	t_element	*current;
	int			pos;

	pivot = get_content(stack_a, (info->elements / 2));
	current = stack_a->top;
	pos = 0;
	while (current)
	{
		if (current->content < pivot)
		{
			put_top(pos, info->elements, stack_a, stack_b);
			instruction("pb", stack_a, stack_b, 1);
			update_info(info);
			pos = 0;
			current = stack_a->top;
		}
		pos++;
		current = current->next;
	}
	put_top(get_position(stack_a, pivot), info->elements, stack_a, stack_b);
	while (stack_b->top)
		instruction("pa", stack_a, stack_b, 1);
	ft_putnbr_fd(pivot, 1);
	write(1, "\n", 1);
	print_stack_bonus(stack_a, stack_b, info->elements);
}
