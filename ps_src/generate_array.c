/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:06:40 by fgata-va          #+#    #+#             */
/*   Updated: 2021/05/03 18:07:57 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *stack_a, int elements)
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

void	swap_ints(int *a, int *b)
{
	int	c;

		c = *a;
		*a = *b;
		*b = c;
}

void	insertion_array(int **array, int len)
{
	int	i;
	int	j;
	int	*to_sort;

	to_sort = *array;
	i = 1;
	while (i < len)
	{
		j = i;
		while (j > 0 && to_sort[j] < to_sort[j - 1])
		{
			swap_ints(to_sort + j, to_sort + (j - 1));
			j--;
		}
		i++;
	}
}

int	*generate_array(t_stack *stack_a, int elements)
{
	int	*array;

	array = stack_to_array(stack_a, elements);
	if (!array)
		return (NULL);
	insertion_array(&array, elements);
	return (array);
}
