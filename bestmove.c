/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestmove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:22:32 by mnassi            #+#    #+#             */
/*   Updated: 2023/02/08 18:36:59 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_search_sis(t_swap **heada)
{
	t_swap	*head;
	int		chr;

	head = (*heada);
	while (head)
	{
		if (head->next->content < head->content)
			chr = head->next->content;
		head = head->next;
		if (head == (*heada))
			break ;
	}
	chr = ft_index(heada, chr);
	return (chr);
}

int	ft_index(t_swap **head, int cmp)
{
	t_swap	*tmp;
	int		i;

	i = 0;
	tmp = (*head);
	while (tmp)
	{
		if (cmp == tmp->content)
			break ;
		i++;
		tmp = tmp->next;
		if (tmp == (*head))
			break ;
	}
	return (i);
}

void	countmoves(t_swap **heada, int ct)
{
	int		i;
	int		j;
	t_swap	*head;

	i = 0;
	j = 0;
	head = (*heada);
	while (j <= ft_lstsize(head))
	{
		if (ct < ft_lstsize(*heada) / 2)
			ra_rotate_a(heada, 1);
		else
			rra_reverse_ra(heada, 1);
		j++;
		if ((*heada) == head)
			break ;
		head = head->next;
	}
}
