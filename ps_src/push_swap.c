/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:15:27 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/07 15:59:46 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push(t_data *data)
{
	data->verbose = 0;
	data->color = 0;
	data->fd = 1;
	data->last_movement = 0;
}

int	main(int argc, char **argv)
{
	t_data	push_swap;
	int		elements;

	init_push(&push_swap);
	if (argc == 1 \
	|| !(init_stacks(argc, argv, &push_swap)))
		return (1);
	elements = ft_stack_len(&push_swap.stack_a);
	if (elements <= 5)
		insertion_sort(&push_swap.stack_a, &push_swap.stack_b);
	else
		bubble_sort(&push_swap.stack_a, &push_swap.stack_b);
	free_stack(&push_swap.stack_a);
	free_stack(&push_swap.stack_b);
	return (0);
}
