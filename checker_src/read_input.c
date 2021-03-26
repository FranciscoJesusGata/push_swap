/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:02:50 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/25 18:48:08 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	add_char(char **dst, char c)
{
	char *tmp;
	int	len;

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
	{
		if (instruction[1] == 'a')
			rotate(stack_a);
		else if (instruction[1] == 'b')
			rotate(stack_b);
		else if (instruction[1] == 'r')
		{
			if(instruction[2] == 'a')
				reverse(stack_a);
			else if (instruction[2] == 'b')
				reverse(stack_b);
		}
	}
}

void	read_input(t_data *checker)
{
	char	buffer;
	char	*instruction;
	int		r;

	instruction = NULL;
	r = get_next_line(0, &instruction);
	while (r > 0)
	{
		if (buffer == '\n' || buffer == 0)
		{
			ft_putstr_fd(instruction, 1);
			write(1, "\n", 1);
			if (instruction)
			{
				check_input(instruction, &checker->stack_a, &checker->stack_b);
				free(instruction);
				instruction = NULL;
			}
			print_stack(&checker->stack_a, &checker->stack_b);
			write(1, "\n", 1);
			buffer = 0;
		}
		add_char(&instruction, buffer);
		r = get_next_line(0, &instruction);
	}
	write(1, "\n", 1);
}
