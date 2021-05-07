/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:59:19 by fgata-va          #+#    #+#             */
/*   Updated: 2021/05/07 09:24:51 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk	*generate_chunks(int elements, int *sorted_list, int count)
{
	int		range;
	t_chunk	*chunk_list;
	int		i;
	int		j;

	chunk_list = (t_chunk *)malloc(sizeof(t_chunk) * count);
	range = (elements / count);
	i = 0;
	j = 0;
	while (i < count - 1)
	{
		chunk_list[i].start = sorted_list[j];
		chunk_list[i].end = sorted_list[j + range - 1];
		i++;
		j += range;
	}
	chunk_list[count - 1].start = sorted_list[j];
	chunk_list[count - 1].end = sorted_list[elements - 1];
	return (chunk_list);
}

int	second_hold(t_stack *stack, int start, int end)
{
	int			i;
	int			last;
	t_element	*current;

	current = stack->top;
	i = 0;
	last = -1;
	while (current)
	{
		if (current->content >= start && current->content <= end)
			last = i;
		i++;
		current = current->next;
	}
	if (last < 0)
		return (-1);
	return (last);
}

int	first_hold(t_stack *stack, int start, int end)
{
	int			i;
	t_element	*current;

	current = stack->top;
	i = 0;
	while (current
		&& (current->content < start || current->content > end))
	{
		i++;
		current = current->next;
	}
	if (i == end && (current->content < start || current->content > end))
		return (-1);
	return (i);
}

void	push_chunk(t_info *info, t_chunk *chunk)
{
	int	hold_first;
	int	hold_second;
	int	hold;
	int	spot;

	hold_first = first_hold(info->stack_a, chunk->start, chunk->end);
	hold_second = second_hold(info->stack_a, chunk->start, chunk->end);
	while (info->stack_a->top && hold_first >= 0 && hold_second >= 0)
	{
		if (hold_first < (info->elements - hold_second))
			hold = hold_first;
		else
			hold = hold_second;
		put_top(hold, info, 'a');
		spot = find_spot_b(info->stack_b, info->stack_a->top->content);
		update_info(info);
		put_top(spot, info, 'b');
		instruction("pb", info->stack_a, info->stack_b, 1);
		update_info(info);
		hold_first = first_hold(info->stack_a, chunk->start, chunk->end);
		hold_second = second_hold(info->stack_a, chunk->start, chunk->end);
	}
}

void	ft_chunk_algo(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int		*sorted_array;
	t_chunk	*chunks;
	int		count;
	int		i;

	sorted_array = generate_array(stack_a, info->elements);
	if (!sorted_array)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1);
	}
	count = linear_function(info->elements);
	chunks = generate_chunks(info->elements, sorted_array, count);
	i = 0;
	while (i < count)
	{
		push_chunk(info, chunks + i);
		i++;
	}
	update_info(info);
	put_top(info->max_pos_b, info, 'b');
	repeat_inst("pa", info, info->elements_b);
	free(chunks);
	free(sorted_array);
}
