/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:53:10 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/01 11:11:23 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_error(char *msg)
{
	ft_putstr_fd("Error\n", 1);
	if (msg)
	{
		ft_putstr_fd(msg, 1);
		write(1, "\n", 1);
	}
}

int	ft_isnumer(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if(!ft_isdigit(*str))
		{
			ft_error("Non numeric argument");
			return (0);
		}
		str++;
	}
	return (1);
}

int	ft_duplicated(t_stack *stack, int num)
{
	t_element *current;

	current = stack->top;
	while (current)
	{
		if (current->content == num)
			return (1);
		current = current->next;
	}
	return (0);
}

int		ft_stack_len(t_stack *stack)
{
	t_element	*current;
	int			len;

	len = 0;
	current = stack->top;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

