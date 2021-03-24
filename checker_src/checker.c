/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:16:10 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/24 12:40:40 by fgata-va         ###   ########.fr       */
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
	write(1, "OK!\n", 4);
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	t_checker	checker;

	i = 1;
	if (argc == 1 || !(init_stacks(argc, argv, &checker.stack_a, &checker.stack_b)))
		return (1);
	read_input(&checker);
	return (0);
}
