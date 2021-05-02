/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:48:42 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/29 19:29:31 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_bonus.h"

void	check_rotations(char *instruction, t_stack *stack_a, t_stack *stack_b)
{
	if (instruction[1] == 'a')
		rotate(stack_a);
	else if (instruction[1] == 'b')
		rotate(stack_b);
	else if (instruction[1] == 'r')
	{
		if (instruction[2] == 0)
		{
			reverse(stack_a);
			reverse(stack_b);
		}
		else if (instruction[2] == 'a')
			reverse(stack_a);
		else if (instruction[2] == 'b')
			reverse(stack_b);
	}
}

void	instruction(char *instruction, t_stack *stack_a,
			t_stack *stack_b, int w)
{
	if (*instruction == 's')
	{
		if (instruction[1] == 'a' || instruction[1] == 's')
			swap(stack_a);
		if (instruction[1] == 'b' || instruction[1] == 's')
			swap(stack_b);
	}
	else if (*instruction == 'p')
	{
		if (instruction[1] == 'a')
			push_element(pop_element(stack_b), stack_a);
		else if (instruction[1] == 'b')
			push_element(pop_element(stack_a), stack_b);
	}
	else if (*instruction == 'r')
		check_rotations(instruction, stack_a, stack_b);
	if (w)
	{
		ft_putstr_fd(instruction, 1);
		write(1, "\n", 1);
	}
	//print_stack_bonus(stack_a, stack_b, 5);
	//sleep(1);
}
