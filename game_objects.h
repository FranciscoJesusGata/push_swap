/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_objects.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:23:49 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/13 12:48:05 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OBJECTS_H
# define GAME_OBJECTS_H

typedef struct s_element
{
	struct s_element	*next;
	int					*content;
}				t_element;

typedef struct s_stack
{
	t_element	*top;
	t_element	*end;
}				t_stack;

#endif
