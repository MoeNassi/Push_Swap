/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:23:44 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/15 01:32:50 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(unsigned int c, int base)
{
	int			len;
	int			stored;
	char		arr[25];
	int			j;

	stored = 0;
	j = 0;
	if (c == 0)
		return (write(1, "0", 1), 1);
	while (c != 0)
	{
		stored = c % base;
		if (stored >= 10)
			arr[++j] = stored + 55;
		if (stored < 10)
			arr[++j] = stored + 48;
		c = c / base;
	}
	len = j;
	while (j > 0)
		write(1, &arr[j--], 1);
	return (len);
}
