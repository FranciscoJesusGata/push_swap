/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:35:33 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/17 11:44:38 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		ft_isnumer(const char *str)
{
	while (str)
	{
		if(!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	fill_stack(int argc, char **argv, t_stack *stack)
{
	int	num;
	int	isNum;
	int	i;

	i = 1;
	num = 0;
	isNum = ft_isnumer(argv[i]);
	while (i < argc && isNum)
	{
		num = ft_atoi(argv[i]);
		push_element(new_element(num), stack);
		i++;
		isNum = ft_isnumer(argv[i]);
	}
	return (isNum);
}

int	init_stacks(int argc, char **argv,\
			t_stack *stack_a, t_stack *stack_b)
{
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !fill_stack(argc, argv, stack_a))
		return (0);
	if (!stack_b)
	{
		free(stack_a);
		return (0);
	}
	return (1);
}

