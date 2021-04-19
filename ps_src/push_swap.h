/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:50:35 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/19 10:01:22 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../common/common.h"

/*
**		Algoritms
*/
void	bubble_sort(t_stack *stack_a, t_stack *stack_b);
void	insertion_sort(t_stack *stack_a, t_stack *stack_b);

/*
**		Utils
*/

void	put_top(int pos, int stack_len, t_stack *a, t_stack *b);
t_element	*find_greatest(t_stack *stack);
int		get_content(t_stack *stack, int pos);

#endif
