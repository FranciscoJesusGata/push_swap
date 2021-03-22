/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:19:57 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/22 11:43:10 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "common/common.h"

void	ft_error(char *msg);
void	read_input(t_stack *stack_a, t_stack *stack_b);
void	check_stack_order(t_stack *a, t_stack *b);

#endif
