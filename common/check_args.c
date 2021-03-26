	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:35:33 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/25 19:26:43 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	check_flags(char **argv, int *i, t_data *data)
{
	if (*argv[*i] == '-')
	{
		if (argv[*i][1] == 'v' && !(data->verbose))
			data->verbose = 1;
		else if (argv[*i][1] == 'c' && !(data->color))
			data->color = 1;
		else if (argv[*i][1] == 'f' && data->fd <= 1)
		{
			*i += 1;
			data->fd = open(argv[*i], O_RDONLY);
			if (data->fd == -1)
			{
				ft_error("File not valid");
				exit(1);
			}
		}
		else
			return (0);
	}
	else
		return (0);
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
	int	i;
	int	start;
	long long	num;

	start = 1;
	i = argc - 1;
	while (start < argc && check_flags(argv, &start, data))
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
