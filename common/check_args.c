	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:35:33 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/20 10:15:33 by fgata-va         ###   ########.fr       */
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

int		ft_isnumer(const char *str)
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

int	check_num(long long content, t_stack *stack)
{
	t_element *current;

	if (content > 2147483647 || content < -2147483648)
	{
		ft_error("Too big argument");
		return (0);
	}
	current = stack->top;
	while (current)
	{
		if (current->content == content)
		{
			ft_error("Duplicated argument");
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	fill_stack(int argc, char **argv, t_stack *stack)
{
	int	i;
	long long	num;

	i = argc - 1;
	while (i > 0)
	{
		if (ft_isnumer(argv[i]))
		{
			num = ft_atol(argv[i]);
			if (check_num(num, stack))
				push_element(new_element(num), stack);
			else
				return (0);
		}
		else
			return (0);
		i--;
	}
	return (1);
}
