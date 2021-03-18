/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:33:49 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/16 10:47:54 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_element	*new_element(int content)
{
	t_element	*new_element;

	new_element = malloc(sizeof(t_element));
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->end = NULL;
	return (stack);
}

