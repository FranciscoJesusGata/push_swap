/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 09:24:10 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/05 16:56:00 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_bonus.h"

void	print_element(t_element *e)
{
	if (e)
	{
		ft_putnbr_fd(e->content, 1);
		write(1, " ", 1);
	}
	else
		write(1, "  ", 2);
}

void	print_stack_bonus(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*a;
	t_element	*b;

	a = stack_a->top;
	b = stack_b->top;
	while (a || b)
	{
		print_element(a);
		print_element(b);
		write(1, "\n", 1);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	ft_putstr_fd("_ _\na b\n", 1);
}
