/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:28:52 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/26 09:33:13 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define BUFF_SIZE 4096

int		match(char a, char b)
{
	return ((a == ')' && b == '(')
	|| (a == ']' && b == '[')
	|| (a == '}' && b == '{'));
}

int		brackets(char *s)
{
	char	tmp[BUFF_SIZE];
	int		i;

	i = 0;
	tmp[0] = 0;
	while (*s)
	{
		if (*s == '(' || *s == '{' || *s == '[')
			tmp[i++] = *s;
		if (*s == ')' || *s == '}' || *s == ']')
			if (!match(*s, tmp[--i]))
				return (0);
		s++;
	}
	return (i == 0 ? 1 : 0);
}

int		main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac > 1)
		while (i < ac)
			brackets(av[i++]) ? write(1, "OK\n", 3) : write(1, "Error\n", 6);
	else
		write(1, "\n", 1);
	return (0);
}
