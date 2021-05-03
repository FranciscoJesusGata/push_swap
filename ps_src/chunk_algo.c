/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:59:19 by fgata-va          #+#    #+#             */
/*   Updated: 2021/05/03 18:56:50 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		linear_function(int elements)
{
	int		y;
	int		b;
	float	m;

	m = (150 - 100) / (15 - 5);
	b = (m * 100) + 5;
	y = (m * elements) + b;
	return (y);
}

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

int		find_spot_b(t_stack *stack, int content)
{
	t_element	*current;
	t_element	*max;
	int			pos;

	if (!stack->top)
		return (0);
	max = find_greatest(stack);
	current = max;
	pos = get_position(stack, current->content);
	while (current->content > content)
	{
		pos++;
		current = current->next;
		if (!current)
		{
			pos = 0;
			current = stack->top;
		}
		if (current == max)
			break ;
	}
	return (pos);
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
	int		max_pos;

	sorted_array = generate_array(stack_a, info->elements);
	if (!sorted_array)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1);
	}
	if (info->elements >= 100 && info->elements < 500)
		count = 5;
	else
		count = 11;
	chunks = generate_chunks(info->elements, sorted_array, 
								linear_function(info->elements));
	i = 0;
	while (i < count)
	{
		push_chunk(info, chunks + i);
		i++;
	}
	max_pos = get_position(info->stack_b, find_greatest(info->stack_b)->content);
	put_top(max_pos, info, 'b');
	repeat_inst("pa", info, ft_stack_len(info->stack_b));
	free(chunks);
	free(sorted_array);
}
