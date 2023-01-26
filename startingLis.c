/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StartingLis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:04:00 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/26 16:32:21 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		longestincrseb(t_swap **heada)
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
		j = countlis(&tmp);
		if (i < j)
		{
			i = j;
			saver = tmp;
		}
		tmp = tmp->next;
		if (tmp == (*heada))
			break ;
	}
	countlis(&saver);
	return (i);
}

int	countlis(t_swap **heada)
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

int		fakeswap(t_swap **heada)
{
	int		old;
	int		new;

	old = longestincrseb(heada);
	sa_swap_a(heada, 0);
	new = longestincrseb(heada);
	if (new > old)
		return (write(1, "sa\n", 3), 1);
	else
		return (sa_swap_a(heada, 0), longestincrseb(heada), 0);
	return (0);
}

void	ft_push0tob(t_swap **heada, t_swap **headb)
{
	int		pushing;
	int		i;

	fakeswap(heada);
	i = ft_lstsize(*heada);
	pushing = longestincrseb(heada);
	while (i > pushing)
	{
		
		if (!(*heada)->key)
		{
			pb_push_b(heada, headb);
			i--;
		}
		else
			ra_rotate_a(heada, 1);
	}
}
