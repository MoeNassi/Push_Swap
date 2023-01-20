/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argvcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:13:38 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/20 18:27:14 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	intchecker(char	**arguments)
{
	int	i;
	int	j;

	i = 0;
	while (arguments[i])
	{
		j = 0;
		if (arguments[i][j] == '-' && arguments[i][j + 1])
			j++;
		while (arguments[i][j])
		{
			if (!ft_isdigit(arguments[i][j]))
				ft_error("Non digit argument");
			j++;
		}
		i++;
	}
}

void	intmaxcheck(char **arguments)
{
	int			i;
	long		pd;
	int			j;
	
	i = 0;
	j = 0;
	pd = 0;
	while (arguments[i])
	{
		pd = ft_atoi(arguments[i]);
		if (pd > MAX_INT || pd < MIN_INT)
			ft_error("the number is above max int");
		i++;
	}
}

void	checkdublicate(char	**arguments)
{
	int		i;
	int		index;

	i = 0;
	while (arguments[i])
	{
		index = i + 1;
		while (arguments[index])
		{
			if (ft_atoi(arguments[i]) == ft_atoi(arguments[index]))
				ft_error("Dublicated Integer");
			index++;
		}
		i++;
	}
}