/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:54:21 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/26 09:19:15 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "check_mate.h"

static int	check(char **grid, int y, int x, int size)
{
	if (grid[y][x] == 'P' && pawn(grid, y, x, size))
		return (1);
	if (grid[y][x] == 'B' && bishop(grid, y, x, size))
		return (1);
	if (grid[y][x] == 'R' && rook(grid, y, x, size))
		return (1);
	if (grid[y][x] == 'Q' && queen(grid, y, x, size))
		return (1);
	return (0);
}

int			solve(char **grid, int size)
{
	int		type;
	int		y;
	int		x;

	type = 0;
	y = -1;
	while (++y < size - 1)
	{
		x = -1;
		while (++x < size - 1)
		{
			if (is_piece(grid[y][x], 4))
				if (check(grid, y, x, size))
					return (1);
		}
	}
	return (0);
}
