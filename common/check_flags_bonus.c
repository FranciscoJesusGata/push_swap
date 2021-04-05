/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:16:16 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/05 16:57:19 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	check_flags_bonus(char **argv, int *i, t_data *data)
{
	if (*argv[*i] == '-')
	{
		if (argv[*i][1] == 'v' && !(data->verbose))
			data->verbose = 1;
		else if (argv[*i][1] == 'f' && data->fd <= 1)
		{
			*i += 1;
			data->fd = open(argv[*i], O_RDONLY);
			if (data->fd == -1)
			{
				ft_error("File not valid");
				exit(1);
			}
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}
