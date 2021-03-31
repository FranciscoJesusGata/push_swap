/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:15:27 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/31 17:37:14 by fgata-va         ###   ########.fr       */
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

	init_push(&push_swap);
	if (argc == 1 ||
	!(init_stacks(argc, argv, &push_swap)))
		return (1);
	bubble_sort(&push_swap.stack_a);
	free_stack(&push_swap.stack_a);
	free_stack(&push_swap.stack_b);
	return (0);
}
