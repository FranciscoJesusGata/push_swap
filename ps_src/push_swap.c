/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:15:27 by fgata-va          #+#    #+#             */
/*   Updated: 2021/05/05 21:06:35 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_info(t_info *info)
{
	info->elements = ft_stack_len(info->stack_a);
	info->elements_b = ft_stack_len(info->stack_b);
	if (info->stack_a->top)
	{
		info->max = find_greatest(info->stack_a);
		info->max_pos = get_position(info->stack_a, info->max->content);
		info->min = find_lowest(info->stack_a);
		info->min_pos = get_position(info->stack_a, info->min->content);
	}
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
