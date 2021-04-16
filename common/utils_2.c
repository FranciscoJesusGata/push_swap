/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:44:54 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/08 13:14:05 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
}

int	count_args(char *arg)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (arg[i])
	{
		while (ft_isdigit(arg[i]))
		{
			if (ft_isspace(arg[i + 1]) || arg[i + 1] == 0)
				cnt++;
			i++;
		}
		if (arg[i])
			i++;
	}
	return (cnt);
}

int	ft_nbrlen(long int n, int base_len)
{
	int	i;

	i = 0;
	if (n < base_len)
		return (1);
	while(n > 0)
	{
		n /= base_len;
		i++;
	}
	return (i);
}
