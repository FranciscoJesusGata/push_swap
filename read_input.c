/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:02:50 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/21 13:25:20 by fgata-va         ###   ########.fr       */
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

/*void	check_input(char *instruction, t_stack *stack_a, t_stack *stack_b)
{
	if (*instruction == 's')
	else if (*instruction == 'p')
	else if (*instruction == 'r')
	else
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1);
	}
	
}*/

void	read_input(t_stack *stack_a, t_stack *stack_b)
{
	char	buffer;
	char	*instruction;
	int		r;

	instruction = NULL;
	r = read(0, &buffer, 1);
	while (r > 0)
	{
		if (buffer == '\n' || buffer == 0)
		{
			ft_putstr_fd(instruction, 1);
			write(1, "\n", 1);
			reverse(stack_a);
			print_stack(stack_a, stack_b);
			write(1, "\n", 1);
			if (instruction)
			{
				free(instruction);
				instruction = NULL;
			}
			buffer = 0;
		}
		add_char(&instruction, buffer);
		r = read(0, &buffer, 1);
	}
	write(1, "\n", 1);
}
