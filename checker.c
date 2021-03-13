/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:16:10 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/11 18:22:40 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		return (1);
	while (i < argc)
	{
		printf("%s ", argv[i++]);
	}
	printf("\n");
	return (0);
}
