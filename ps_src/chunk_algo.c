/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:59:19 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/27 21:56:08 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(int *list, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		ft_putnbr_fd(list[i], 1);
		write(1, ", ",1);
		i++;
	}
	ft_putnbr_fd(list[i], 1);

	write (1, "\n", 1);
}

int	*stack_to_list(t_stack *stack_a, int elements)
{
	int			*list;
	t_element	*current;
	int			i;

	current = stack_a->top;
	list = (int *)ft_calloc(elements, sizeof(int));
	if (!list)
		return (NULL);
	i = 0;
	while (current)
	{
		list[i] = current->content;
		i++;
		current = current->next;
	}
	return (list);
}

void	choose_pivot(int *list, int **pivot, int start, int len)
{
	int	a;
	int	b;
	int	c;

	a = list[start];
	b = list[len / 2];
	c = list[len];
	if ((a > b && a < c) || (a < b && a > c))
		*pivot = list + start;
	else if ((b > a && b < c) || (b < a && b > c))
		*pivot = list + (len / 2);
	else
		*pivot = list + len;
}

void	swap_ints(int *a, int *b)
{
	int	c;

	if (*a != *b)
	{
		c = *a;
		*a = *b;
		*b = c;
	}
}

int	position_pivot(int *list, int *pivot, int start, int end)
{
	int	i;
	int	j;

	i = start;
	j = end - 1;
	ft_printf("pivot %d\n", *pivot);
	while (j > i)
	{
		if (list[i] > *pivot && list[j] < *pivot)
			swap_ints(list + i, list + j);
		if (list[i] < *pivot && i != j)
			i++;
		if (list[j] > *pivot && i != j)
			j--;
	}
	swap_ints(pivot, list + j);
	return (j);
}

void	list_quicksort(int **list, int start, int end)
{
	int	*pivot;
	int	pivot_pos;

	pivot = NULL;
	if (start < end)
	{
		choose_pivot(*list, &pivot, start, end);
		swap_ints(pivot, *list + end);
		pivot = *list + end;
		pivot_pos = position_pivot(*list, pivot, start, end);
		list_quicksort(list, start, pivot_pos - 1);
		//list_quicksort(list, pivot_pos + 1, end);
	}
}

void	ft_chunk_algo(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int		*sorted_list;

	sorted_list = stack_to_list(stack_a, info->elements);
	if (!sorted_list)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1);
	}
	print_list(sorted_list, info->elements);
	list_quicksort(&sorted_list, 0, (info->elements - 1));
	print_list(sorted_list, info->elements);
}
