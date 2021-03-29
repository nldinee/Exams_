/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 06:42:41 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/01 06:43:45 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "check_mate.h"

int		main(int ac, char **av)
{
	char	**grid;
	int		i;

	i = 0;
	if (ac > 1)
	{
		grid = parse(ac, av);
		solve(grid, ac) ? write(1, "Success\n", 8) : write(1, "Fail\n", 5);
		while (i < ac)
			free(grid[i++]);
		free(grid);
	}
	else
		write(1, "\n", 1);
	return (0);
}
