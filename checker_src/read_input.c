/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:02:50 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/05 16:51:57 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	add_char(char **dst, char c)
{
	char	*tmp;
	int		len;

	if (!*dst)
	{
		*dst = ft_calloc(2, 1);
		**dst = c;
	}
	else
	{
		len = ft_strlen(*dst);
		tmp = ft_calloc(len + 2, 1);
		ft_memcpy(tmp, *dst, len);
		tmp[len] = c;
		free(*dst);
		*dst = tmp;
		tmp = NULL;
	}
}

void	rotations(char *instruction, t_stack *stack_a, t_stack *stack_b)
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

void	check_input(char *instruction, t_stack *stack_a, t_stack *stack_b)
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
		rotations(instruction, stack_a, stack_b);
}

void	read_input(t_data *checker)
{
	char	*instruction;
	int		r;

	instruction = NULL;
	r = get_next_line(checker->fd, &instruction);
	while (r > 0 && !(check_stack_order(&checker->stack_a)
			&& !checker->stack_b.top))
	{
		if (instruction)
		{
			check_input(instruction, &checker->stack_a, &checker->stack_b);
			free(instruction);
			instruction = NULL;
		}
		if (checker->verbose)
			print_stack_bonus(&checker->stack_a, &checker->stack_b);
		r = get_next_line(checker->fd, &instruction);
	}
	if (!(check_stack_order(&checker->stack_a)) || checker->stack_b.top)
		write(1, "KO\n", 3);
	else
		write(1, "OK!\n", 4);
}
