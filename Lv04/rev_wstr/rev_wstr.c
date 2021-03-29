/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:44:31 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/26 09:45:39 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		count_word(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (str[++i])
		if (str[i] == ' ' || str[i] == '\t')
			count++;
	return (str[0] != '\0' ? count + 1 : 0);
}

void	rev_wstr(char *str)
{
	int	words;
	int	now;
	int	saved;

	now = 0;
	words = count_word(str);
	while (str[now])
		now++;
	now--;
	saved = now;
	while (saved >= 0)
	{
		while (now >= 0 && str[now] != ' ' && str[now] != '\t')
			now--;
		saved = now - 1;
		now++;
		while (str[now] != '\0' && str[now] != ' ' && str[now] != '\t')
			write(1, &str[now++], 1);
		if (words-- > 1)
			write(1, " ", 1);
		now = saved;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
