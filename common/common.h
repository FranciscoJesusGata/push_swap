/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 09:31:25 by fgata-va          #+#    #+#             */
/*   Updated: 2021/05/05 20:42:12 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# ifndef BONUS
#  define BONUS 0
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../Libft/ft_printf/ft_printf.h"

typedef struct s_element
{
	struct s_element	*next;
	int					content;
}						t_element;

typedef struct s_stack
{
	t_element	*top;
	t_element	*end;
}				t_stack;

typedef struct s_data
{
	int		verbose;
	int		fd;
	t_stack	stack_a;
	t_stack	stack_b;
	int		max_len;
}			t_data;

/*
** Stack management
*/

t_element	*new_element(int content);
t_stack		*new_stack(void);
int			fill_stack(int argc, char **argv, t_data *data);
int			init_stacks(int argc, char **argv, t_data *data);
void		free_stack(t_stack *stack);

/*
** Instructions
*/

void		push_element(t_element *elem, t_stack *stack);
t_element	*pop_element(t_stack *stack);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		reverse(t_stack *stack);
void		instruction(char *instruction, t_stack *stack_a,
				t_stack *stack_b, int w);

/*
** Checkers
*/

int			check_stack_order(t_stack *a);
int			check_args(char *arg, t_stack *stack, long long *num);
int			multi_args(char *arg, t_data *data);
int			check_flags_bonus(char **argv, int *i, t_data *data);

/*
** Utils
*/

int			ft_isnumer(const char *str);
void		ft_error(char *msg);
int			ft_isnumer(const char *str);
int			ft_stack_len(t_stack *stack);
int			ft_duplicated(t_stack *stack, int num);
int			ft_isspace(char c);
void		free_matrix(char **matrix);
int			count_args(char *arg);
int			ft_nbrlen(long int n, int base_len);
int			ft_maxlen(t_stack *stack);

#endif
