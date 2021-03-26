/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:19:57 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/25 18:40:59 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../common/common.h"
# define SWAP_A 1
# define SWAP_B 2
# define SWAP_AB 3
# define PUSH_A 4
# define PUSH_B 5
# define ROT_A 6
# define ROT_B 7
# define ROT_AB 8
# define REV_A 9
# define REV_B 10
# define REV_AB 11

void	ft_error(char *msg);
void	read_input(t_data *checker);
int	check_stack_order(t_stack *a);

#endif
