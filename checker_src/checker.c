/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:16:10 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/25 19:25:53 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	check_stack_order(t_stack *a)
{
	t_element *current;

	current = a->top;
	while (current)
	{
		if (current->next && current->next->content < current->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	init_struct(t_data *checker)
{
	checker->verbose = 0;
	checker->color = 0;
	checker->fd = 0;
	checker->last_movement = 0;
}

int	main(int argc, char **argv)
{
	int	i;
	t_data	checker;

	i = 1;
	init_struct(&checker);
	if (argc == 1 ||
	!(init_stacks(argc, argv, &checker)))
		return (1);
	read_input(&checker);
	return (0);
}
