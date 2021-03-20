/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:16:10 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/20 13:20:35 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	check_stack_order(t_stack *a, t_stack *b)
{
	t_element *current;
	
	if (b->top && b->end)
	{
		write(1, "KO\n", 3);
		return ;
	}
	current = a->top;
	while (current)
	{
		if (current->next && current->next->content < current->content)
		{
			write(1, "KO\n", 3);
			return ;
		}
		current = current->next;
	}
	write(1, "OK!\n", 4);
}

int	main(int argc, char **argv)
{
	int	i;
	t_stack	stack_a;
	t_stack	stack_b;

	i = 1;
	if (argc == 1 || !(init_stacks(argc, argv, &stack_a, &stack_b)))
		return (1);
	read_input(&stack_a, &stack_b);
	return (0);
}
