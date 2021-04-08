/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:02:50 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/07 16:09:11 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	add_char(char **dst, char c)
{
	char	*tmp;
	int		len;

	if (!*dst)
	{
		*dst = ft_calloc(2, 1);
		**dst = c;
	}
	else
	{
		len = ft_strlen(*dst);
		tmp = ft_calloc(len + 2, 1);
		ft_memcpy(tmp, *dst, len);
		tmp[len] = c;
		free(*dst);
		*dst = tmp;
		tmp = NULL;
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
