/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:19:57 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/24 11:58:11 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../common/common.h"
typedef struct s_checker
{
    int	verbose;
    int	color;
	int	fd;
	t_stack	stack_a;
	t_stack	stack_b;
}               t_checker;

void	ft_error(char *msg);
void	read_input(t_checker *checker);
int	check_stack_order(t_stack *a);

#endif
