/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:48:04 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/22 12:29:05 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_BONUS_H
# define COMMON_BONUS_H
# include "common.h"

int		check_flags_bonus(char **argv, int *i, t_data *data);
void	print_stack_bonus(t_stack *stack_a, t_stack *stack_b, int width);

#endif
