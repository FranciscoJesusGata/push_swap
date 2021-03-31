/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:49:01 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/31 17:36:40 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stack_len(t_stack *stack)
{
	t_element	*current;
	int			len;

	len = 0;
	current = stack->top;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

void	bubble_sort(t_stack *stack)
{
	int	steps;
	int	i;
	int	j;

	i = 0;
	steps = ft_stack_len(stack);
	while (i < steps && !(check_stack_order(stack)))
	{
		j = 0;
		while (j < steps - 1)
		{
			if (stack->top->content > stack->top->next->content)
			{
				swap(stack);
				write(1, "sa\n", 3);
			}
			rotate(stack);
			write(1, "ra\n", 3);
			j++;
		}
		rotate(stack);
		write(1, "ra\n", 3);
		i++;
	}
}
