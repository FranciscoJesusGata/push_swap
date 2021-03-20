/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:02:50 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/20 11:10:06 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	read_input(t_stack *stack_a, t_stack *stack_b)
{
	char	buffer;
	int		r;

	print_stack(stack_a, stack_b);
	ft_putstr_fd("actions>", 1);
	r = read(0, &buffer, 1);
	while (r > 0)
	{
		if (buffer == '\n' || buffer == 0)
		{
			reverse(stack_a);
			print_stack(stack_a, stack_b);
		}
		ft_putstr_fd("actions>", 1);
		r = read(0, &buffer, 1);
	}
	write(1, "\n", 1);
}
