/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:19:57 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/05 17:32:29 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../common/common.h"
# include "../common/common_bonus.h"

void	ft_error(char *msg);
void	read_input(t_data *checker);
int		check_stack_order(t_stack *a);
int		get_next_line(int fd, char **line);

#endif
