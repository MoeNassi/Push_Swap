/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:58:30 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/20 18:49:19 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Printf/ft_printf.h"
#include "push_swap.h"

char	**ft_parsing(int argc, char **argv)
{
	int		i;
	char	*tmp;
	char	**spliting;

	i = 0;
	tmp = ft_strjoin(argc - 1, argv + 1, " ");
	spliting = ft_split(tmp, ' ');
	intchecker(spliting);
	intmaxcheck(spliting);
	checkdublicate(spliting);
	return (spliting);
}