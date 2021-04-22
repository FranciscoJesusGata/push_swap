/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:16:10 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/22 13:42:47 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_struct(t_data *checker)
{
	checker->verbose = 0;
	checker->fd = 0;
}

int	main(int argc, char **argv)
{
	t_data	checker;

	init_struct(&checker);
	if (argc == 1 \
		|| !(init_stacks(argc, argv, &checker)))
		return (1);
	if (checker.verbose)
		checker.max_len = ft_maxlen(&checker.stack_a);
	read_input(&checker);
	free_stack(&checker.stack_a);
	free_stack(&checker.stack_b);
	return (0);
}
