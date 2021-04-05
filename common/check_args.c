/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:35:33 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/05 16:40:59 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
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
		if ((check_args(argv[i], &data->stack_a, &num)))
			push_element(new_element(num), &data->stack_a);
		else
			return (0);
		i--;
	}
	if (!data->stack_a.top)
		return (0);
	return (1);
}
