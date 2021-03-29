/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 06:44:54 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/26 09:18:17 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int		pawn(char **grid, int y, int x, int size)
{
	if (y && x && grid[y - 1][x - 1] == 'K')
		return (1);
	if (y && x < size - 2 && grid[y - 1][x + 1] == 'K')
		return (1);
	if (y < size - 2 && x && grid[y + 1][x - 1] == 'K')
		return (1);
	if (y < size - 2 && x < size - 2 && grid[y + 1][x + 1] == 'K')
		return (1);
	return (0);
}

int		bishop(char **grid, int y, int x, int size)
{
	int	i;
	int	j;

	i = y;
	j = x;
	while (i && j)
		if (is_piece(grid[--i][--j], 5))
			return (grid[i][j] == 'K' ? 1 : 0);
	i = y;
	j = x;
	while (i && j < size - 2)
		if (is_piece(grid[--i][++j], 5))
			return (grid[i][j] == 'K' ? 1 : 0);
	i = y;
	j = x;
	while (i < size - 2 && j)
		if (is_piece(grid[++i][--j], 5))
			return (grid[i][j] == 'K' ? 1 : 0);
	i = y;
	j = x;
	while (i < size - 2 && j < size - 2)
		if (is_piece(grid[++i][++j], 5))
			return (grid[i][j] == 'K' ? 1 : 0);
	return (0);
}

int		rook(char **grid, int y, int x, int size)
{
	int	i;
	int	j;

	i = y;
	j = x;
	while (j)
		if (is_piece(grid[i][--j], 5))
			return (grid[i][j] == 'K' ? 1 : 0);
	j = x;
	while (j < size - 2)
		if (is_piece(grid[i][++j], 5))
			return (grid[i][j] == 'K' ? 1 : 0);
	j = x;
	while (i)
		if (is_piece(grid[--i][j], 5))
			return (grid[i][j] == 'K' ? 1 : 0);
	i = y;
	while (i < size - 2)
		if (is_piece(grid[++i][j], 5))
			return (grid[i][j] == 'K' ? 1 : 0);
}

int		queen(char **grid, int y, int x, int size)
{
	return ((rook(grid, y, x, size) || bishop(grid, y, x, size) ? 1 : 0));
}
