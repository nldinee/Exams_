/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <exam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:03:52 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 09:26:31 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "biggest_pal.h"

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		is_pal(char *s, int start, int end)
{
	while (start < end)
		if (s[start++] != s[end--])
			return (0);
	return (1);
}

t_str	init_struct(char *s)
{
	t_str	pal;

	pal.start = 0;
	pal.save = 0;
	pal.size = ft_strlen(s) - 1;
	return (pal);
}

void	biggest_pal(char *s, t_str pal)
{
	while (s[pal.start])
	{
		pal.end = pal.size;
		while (pal.start >= 0)
		{
			if (is_pal(s, pal.start, pal.end))
			{
				while (pal.start <= pal.end)
					write(1, &s[pal.start++], 1);
				return ;
			}
			else
			{
				pal.start--;
				pal.end--;
			}
		}
		pal.save++;
		pal.start = pal.save;
	}
}


int		main(int ac, char **av)
{
	if (ac == 2)
		biggest_pal(av[1], init_struct(av[1]));
	write(1, "\n", 1);
	return (0);
}