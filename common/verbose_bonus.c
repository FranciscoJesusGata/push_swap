/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 09:24:10 by fgata-va          #+#    #+#             */
/*   Updated: 2021/05/05 20:41:55 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_bonus.h"
#include <stdio.h>

void	repeat_char(int c, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		write(1, &c, 1);
		i++;
	}
}

void	print_element(t_element *e, int width)
{
	write(1, "| ", 2);
	if (e)
		ft_printf("%*d", width, e->content);
	else
		ft_printf("%*s", width, " ");
	write(1, " |", 2);
}

void	print_stack_bonus(t_stack *stack_a, t_stack *stack_b, int width)
{
	t_element	*a;
	t_element	*b;
	int			len;

	len = (width + 4) * 2;
	repeat_char('_', len);
	write(1, "\n", 1);
	a = stack_a->top;
	b = stack_b->top;
	while (a || b)
	{
		print_element(a, width);
		print_element(b, width);
		write(1, "\n", 1);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	repeat_char('_', len);
	write(1, "\n", 1);
	width = len / 4 + 1;
	ft_printf("%*c", width, 'a');
	ft_printf("%*c\n", width + 1, 'b');
}
