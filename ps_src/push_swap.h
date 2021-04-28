/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:50:35 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/28 21:17:30 by fgata-va         ###   ########.fr       */
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
	int			elements_b;
	int			max_pos;
	int			min_pos;
}				t_info;

typedef struct	s_chunk
{
	int			start;
	int			end;
}				t_chunk;

typedef struct	s_pivot
{
	int			pos;
	t_element	*element;
	int			sorted;
}				t_pivot;

/*
**		Algoritms
*/
void		bubble_sort(t_stack *stack_a, t_stack *stack_b);
void		insertion_sort(t_stack *stack_a, t_info *info);
void		quicksort(t_stack *stack_a, t_stack *stack_b, t_info *info);
void		ft_chunk_algo(t_stack *stack_a, t_stack *stack_b, t_info *info);

/*
**		Utils
*/

void		put_top(int pos, t_info *info, int stack);
void		repeat_inst(char *inst, t_info *info, int steps);
t_element	*find_greatest(t_stack *stack);
int			get_content(t_stack *stack, int pos);
int			get_position(t_stack *stack, int content);
t_element	*find_lowest(t_stack *stack);
void		update_info(t_info *info);
t_element	*get_element(t_stack *stack, int pos);
int			*generate_array(t_stack *stack, int elements);

#endif
