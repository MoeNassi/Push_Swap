/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argvcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:13:38 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/21 17:26:10 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nospace(char **arguments)
{
	int		i;
	int		j;
	int		flag;

	i = -1;
	j = -1;
	flag = 0;
	while (arguments[++i])
	{
		if (ft_strncmp(arguments[i], " ", 1))
		{
			while (arguments[i][++j])
			{
				if (ft_isdigit(arguments[i][j]))
					break ;
				if (arguments[i][j + 1] == '\0')
					flag = 1;
			}
			if (flag)
				ft_error("The string is full with spaces");
		}
		if (ft_strncmp(arguments[i], "\0", 1))
			ft_error("There's a empty string");
	}
}

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
			ft_error("the number is above Max int or Min int");
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
