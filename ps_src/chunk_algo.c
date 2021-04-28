/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:59:19 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/28 16:59:46 by fgata-va         ###   ########.fr       */
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
		ft_printf("chunk_list[%d] -> start: %d, end %d. from %d to %d\n", 
				i, chunk_list[i].start, chunk_list[i].end, j, j + range - 1);
		i++;
		j += range;
	}
	chunk_list[count - 1].start = sorted_list[j];
	chunk_list[count - 1].end = sorted_list[elements - 1];
	ft_printf("chunk_list[%d] -> start: %d, end %d. from %d to %d\n", 
				i, chunk_list[4].start, chunk_list[4].end, j, elements - 1);
	return (chunk_list);
}

void	rise_hold(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk, int len)
{
	int			i;
	int			j;
	int			last;
	t_element	*current;

	i = 0;
	current = stack_a->top;
	while (current
			&& current->content < chunk->start && current->content > chunk->end)
	{
		i++;
		current = current->next;
	}
	j = i;
	last = j;
	while (current)
	{
		if (current->content >= chunk->start && current->content <= chunk->end)
			last = j;
		j++;
		current = current->next;
	}
	if (i < (len - last))
		put_top(i, len, stack_a, stack_b);
	else
		put_top(j, len, stack_a, stack_b);
	print_stack_bonus(stack_a, stack_b, 4);
}

void	ft_chunk_algo(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int		*sorted_array;
	t_chunk	*chunks;
	int		count;
	//int		i;

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
	ft_putnbr_fd(info->elements, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(count, 1);
	write(1, "\n", 1);
	chunks = generate_chunks(info->elements, sorted_array, count);
	//i = 0;
	/*while (i < count)
	{
		rise_hold(stack_a, stack_b, chunks + i, info->elements);
		i++;
	}*/
	free(chunks);
	free(sorted_array);
}
