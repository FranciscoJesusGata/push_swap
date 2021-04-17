/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:02:50 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/16 12:48:31 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_input(char *input, t_data *checker)
{
	size_t	len;

	len = ft_strlen(input);
	if (len < 2)
	{
		// Error
	}
	else if (!(ft_strncmp(input, "sa", 3)) || !(ft_strncmp(input, "sb", 3))
			|| !(ft_strncmp(input, "ss", 3)) || !(ft_strncmp(input, "pa", 3))
			|| !(ft_strncmp(input, "pb", 3)) || !(ft_strncmp(input, "ra", 3))
			|| !(ft_strncmp(input, "rb", 3)) || !(ft_strncmp(input, "rr", 4)))
	{
		instruction(input, &checker->stack_a, &checker->stack_b, 0);
		free(input);
		input = NULL;
	}
}

void	read_input(t_data *checker)
{
	char	*inst;
	int		r;

	inst = NULL;
	r = 1;
	while (r > 0 && !(check_stack_order(&checker->stack_a)
			&& !checker->stack_b.top))
	{
		r = get_next_line(checker->fd, &inst);
		if (inst)
		{
			instruction(inst, &checker->stack_a, &checker->stack_b, 0);
			free(inst);
			inst = NULL;
		}
		if (checker->verbose)
			print_stack_bonus(&checker->stack_a, &checker->stack_b);
	}
	if (!(check_stack_order(&checker->stack_a)) || checker->stack_b.top)
		write(1, "KO\n", 3);
	else
		write(1, "OK!\n", 4);
}
