/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:52:52 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/26 09:47:38 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		numlen(int nbr)
{
	int				size;

	size = 1;
	if (nbr < 0)
		size++;
	while (nbr / 10)
	{
		size++;
		nbr /= 10;
	}
	return (size);
}

char	*ft_itoa(int nbr)
{
	int				size;
	char			*result;
	long			work_value;

	size = numlen(nbr);
	work_value = nbr;
	if (!(result = (char*)malloc(sizeof(*result) * (size + 1))))
		return (NULL);
	result[size--] = '\0';
	result[0] = (nbr < 0 ? '-' : '0');
	if (nbr < 0)
		work_value = -work_value;
	while (work_value > 0)
	{
		result[size--] = work_value % 10 + '0';
		work_value /= 10;
	}
	return (result);
}
