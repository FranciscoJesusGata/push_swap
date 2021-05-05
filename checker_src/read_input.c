/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:02:50 by fgata-va          #+#    #+#             */
/*   Updated: 2021/05/05 20:42:46 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_input(char *input, t_data *checker)
{
	size_t	l;

	l = ft_strlen(input);
	if ((l >= 2 || l == 0)
		&& (!(ft_strncmp(input, "sa", l)) || !(ft_strncmp(input, "sb", l))
			|| !(ft_strncmp(input, "ss", l)) || !(ft_strncmp(input, "pa", l))
			|| !(ft_strncmp(input, "pb", l)) || !(ft_strncmp(input, "ra", l))
			|| !(ft_strncmp(input, "rb", l)) || !(ft_strncmp(input, "rr", l))
			|| !(ft_strncmp(input, "rra", l)) || !(ft_strncmp(input, "rrb", l))
			|| !(ft_strncmp(input, "rrr", l))))
	{
		instruction(input, &checker->stack_a, &checker->stack_b, 0);
		free(input);
		input = NULL;
	}
	else
	{
		free(input);
		free_stack(&checker->stack_a);
		free_stack(&checker->stack_b);
		ft_error("Invalid instruction");
		exit(1);
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
			check_input(inst, checker);
		if (checker->verbose)
			print_stack_bonus(&checker->stack_a, &checker->stack_b,
				checker->max_len);
	}
	if (!(check_stack_order(&checker->stack_a)) || checker->stack_b.top)
		write(1, "KO\n", 3);
	else
		write(1, "OK!\n", 4);
}
