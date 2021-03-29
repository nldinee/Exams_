/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 06:46:00 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/26 09:17:33 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "check_mate.h"

int			is_piece(char c, int num)
{
	int		i;
	char	*pieces;

	i = -1;
	pieces = "PBRQK";
	while (++i < num)
		if (c == pieces[i])
			return (1);
	return (0);
}

static char	*build_grid(char *av, int ac)
{
	char	*row;
	int		i;

	i = -1;
	row = (char*)malloc(sizeof(char) * ac);
	while (av[++i])
		row[i] = (is_piece(av[i], 5) ? av[i] : '.');
	row[i] = '\0';
	return (row);
}

char		**parse(int size, char **av)
{
	char	**grid;
	int		row;
	int		y;

	row = 0;
	y = 0;
	grid = (char**)malloc(sizeof(char*) * size);
	while (++row < ac)
		grid[y++] = build_grid(av[row], size);
	grid[y] = 0;
	return (grid);
}
