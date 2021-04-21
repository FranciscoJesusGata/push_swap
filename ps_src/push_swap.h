/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:50:35 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/21 17:11:03 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../common/common_bonus.h"

typedef struct	s_info
{
	t_element	*max;
	t_element	*min;
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			elements;
	int			max_pos;
	int			min_pos;
}				t_info;

/*
**		Algoritms
*/
void		bubble_sort(t_stack *stack_a, t_stack *stack_b);
void		insertion_sort(t_stack *stack_a, t_stack *stack_b, t_info *info);

/*
**		Utils
*/

void		put_top(int pos, int stack_len, t_stack *a, t_stack *b);
t_element	*find_greatest(t_stack *stack);
int			get_content(t_stack *stack, int pos);
int			get_position(t_stack *stack, int content);
t_element	*find_lowest(t_stack *stack);
void		update_info(t_info *info);

#endif
