/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:16:10 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/18 17:39:00 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_struct(t_data *checker)
{
	checker->verbose = 0;
	checker->color = 0;
	checker->fd = 0;
	checker->last_movement = 0;
}

int	main(int argc, char **argv)
{
	t_data	checker;

	init_struct(&checker);
	if (argc == 1 \
		|| !(init_stacks(argc, argv, &checker)))
		return (1);
	read_input(&checker);
	free_stack(&checker.stack_a);
	free_stack(&checker.stack_b);
	return (0);
}
