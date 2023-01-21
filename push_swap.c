/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:36:42 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/21 13:50:02 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps/ft_printf.h"

int main(int ac, char **av)
{
	t_swap	ot;
	int		i;

	i = 0;
	ot.za = ft_parsing(ac, av);
	while (ot.za[i])
		ft_printf("%s\n", ot.za[i++]);
	return (0);
}