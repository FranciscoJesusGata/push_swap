/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:15:27 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/29 19:07:08 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_info(t_info *info)
{
	info->elements = ft_stack_len(info->stack_a);
	info->elements_b = ft_stack_len(info->stack_b);
	info->max = find_greatest(info->stack_a);
	info->max_pos = get_position(info->stack_a, info->max->content);
	info->min = find_lowest(info->stack_a);
	info->min_pos = get_position(info->stack_a, info->min->content);
}

void	sort_three(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	t_element *greatest;
	t_element *lowest;

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
		put_top(find_spot(stack_a, stack_b->top->content, 0), info, 'a');
		instruction("pa", stack_a, stack_b, 1);
		update_info(info);
	}
	update_info(info);
	put_top(info->min_pos, info, 'a');
}

void	get_data(t_info *info, t_data *push_swap)
{
	info->stack_a = &push_swap->stack_a;
	info->stack_b = &push_swap->stack_b;
	info->elements = ft_stack_len(info->stack_a);
	info->elements_b = ft_stack_len(info->stack_b);
	if (info->elements > 0)
	{
		info->max = find_greatest(info->stack_a);
		info->max_pos = get_position(info->stack_a, info->max->content);
		info->min = find_lowest(info->stack_a);
		info->min_pos = get_position(info->stack_a, info->min->content);
	}
}

void	init_push(t_data *data)
{
	data->verbose = 0;
	data->fd = 1;
}

int	main(int argc, char **argv)
{
	t_data	push_swap;
	t_info	info;

	init_push(&push_swap);
	if (argc == 1 || !(init_stacks(argc, argv, &push_swap)))
		return (1);
	get_data(&info, &push_swap);
	if (info.elements > 0 && !(check_stack_order(&push_swap.stack_a)))
	{
		if (info.elements == 2)
			instruction("sa", info.stack_a, info.stack_b, 1);
		else if (info.elements == 3)
			sort_three(info.stack_a, info.stack_b, &info);
		else if (info.elements < 6)
			sort_four_five(info.stack_a, info.stack_b, &info);
		else if (info.elements < 100)
			insertion_sort(info.stack_a, &info);
		else
			ft_chunk_algo(info.stack_a, info.stack_b, &info);
	}
	free_stack(&push_swap.stack_a);
	free_stack(&push_swap.stack_b);
	return (0);
}
