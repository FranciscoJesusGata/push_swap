/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:35:33 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/08 12:04:37 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_bonus.h"

int	check_stack_order(t_stack *a)
{
	t_element	*current;

	current = a->top;
	while (current)
	{
		if (current->next && current->next->content < current->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	check_args(char *arg, t_stack *stack, long long *num)
{
	if (!ft_isnumer(arg))
		return (0);
	*num = ft_atol(arg);
	if (*num > 2147483647 || *num < -2147483648)
	{
		ft_error("Too big argument");
		return (0);
	}
	if ((ft_duplicated(stack, (int)*num)))
	{
		ft_error("Duplicated argument");
		return (0);
	}
	return (1);
}

int	multi_args(char *arg, t_data *data)
{
	char		**args;
	int			len;
	long long	num;

	len = 0;
	args = ft_split(arg, ' ');
	while (args[len])
		len++;
	len--;
	while (len >= 0)
	{
		if ((check_args(args[len], &data->stack_a, &num)))
		{
			ft_printf("%s Pushed\n", args[len]);
			push_element(new_element(num), &data->stack_a);
		}
		else
		{
			free_matrix(args);
			return (0);
		}
		len--;
	}
	free_matrix(args);
	return (1);
}

int	fill_stack(int argc, char **argv, t_data *data)
{
	int			i;
	int			start;
	long long	num;

	start = 1;
	i = argc - 1;
	while (start < argc && check_flags_bonus(argv, &start, data))
		start++;
	while (i >= start)
	{
		if (count_args(argv[i]) > 1)
		{
			if (!(ft_strlen(argv[i])) || !(multi_args(argv[i], data)))
				return (0);
		}
		else if ((check_args(argv[i], &data->stack_a, &num)))
			push_element(new_element(num), &data->stack_a);
		else
			return (0);
		i--;
	}
	if (!data->stack_a.top)
		return (0);
	return (1);
}
