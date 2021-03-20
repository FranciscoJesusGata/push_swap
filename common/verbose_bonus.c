/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 09:24:10 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/20 11:00:43 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_element *a;
	t_element *b;

	a = stack_a->top;
	b = stack_b->top;
	while (a || b)
	{
		if (a)
		{
			ft_putnbr_fd(a->content, 1);
			write(1, " ", 1);
			a = a->next;
		}
		else
			write(1, "  ", 2);
		if (b)
		{
			ft_putnbr_fd(b->content, 1);
			write(1, " ", 1);
			b = b->next;
		}
		else
			write(1, "  ", 2);
		write(1, "\n", 1);
	}
	ft_putstr_fd("_ _\na b\n", 1);
}
