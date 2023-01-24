/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StartingLis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:04:00 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/24 15:38:33 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	longestincrseb(t_swap **heada)
{
	t_swap	*tmp;
	t_swap	*saver;
	int		i;
	int		j;

	i = 0;
	j = 0;
	
	tmp = (*heada);
	while (1)
	{
		j = countLIS(&tmp);
		if (i < j)
		{
			i = j;
			saver = tmp;
		}
		tmp = tmp->next;
		if (tmp == (*heada))
			break ;
	}
	countLIS(&saver);
}

int	countLIS(t_swap **heada)
{
	int		i;
	t_swap	*save;
	t_swap	*keep;

	i = 0;
	save = (*heada);
	keep = save;
	while (1)
	{
		save->key = 0;
		if (keep->content <= save->content)
		{
			keep = save;
			keep->key = 1;
			i++;
		}
		save = save->next;
		if (save == (*heada))
			break ;
	}
	return (i);
}
