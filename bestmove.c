/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestmove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:22:32 by mnassi            #+#    #+#             */
/*   Updated: 2023/02/18 15:21:13 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_lst(t_swap **head)
{
	t_swap	*head1;
	int		i;

	i = 0;
	head1 = (*head);
	while (head1)
	{
		head1->index = i++;
		head1 = head1->next;
		if (head1 == (*head))
			break ;
	}
}

t_swap	*ft_find_so(t_swap **heada, t_swap *headb, t_move *mv)
{
	t_swap	*head;
	t_swap	*next;
	int		i;

	i = 0;
	head = (*heada)->prev;
	next = (*heada);
	while (1)
	{
		if (((*headb).content < next->content
				&& head->content < (*headb).content)
			|| (head->content > next->content
				&& ((*headb).content > head->content
					|| (*headb).content < next->content)))
		{
			mv->movea = i;
			return (headb);
		}
		head = head->next;
		next = next->next;
		i++;
		if (next == (*heada))
			break ;
	}
	return (NULL);
}

void	searchfr(t_move *mv)
{
	if (mv->moveb >= 0 && mv->movea >= 0)
		whosbetter(mv);
	else if (mv->moveb < 0 && mv->movea < 0)
		whosbetter(mv);
	else if (ft_abs(mv->movea) + ft_abs(mv->moveb) <= mv->total)
	{
		mv->total = ft_abs(mv->movea) + ft_abs(mv->moveb);
		mv->bestmovea = mv->movea;
		mv->bestmoveb = mv->moveb;
	}
}

int	ft_search_sis(t_swap **heada)
{
	t_swap	*head;
	int		chr;
	int		nmb;

	nmb = 0;
	head = (*heada);
	while (head)
	{
		if (head->next->content < head->content)
			chr = head->next->content;
		head = head->next;
		if (head == (*heada))
			break ;
	}
	nmb = ft_index(heada, chr);
	return (nmb);
}

void	ft_search_forb(t_swap **heada, t_swap **headb, t_move *mv)
{
	t_swap	*head;
	t_swap	*copy;
	int		size;

	size = ft_lstsize(*headb);
	while (size > 0)
	{
		mv->total = INT_MAX;
		ft_index_lst(headb);
		head = (*headb);
		while (headb)
		{
			copy = ft_find_so(heada, *headb, mv);
			mv->moveb = copy->index;
			checkmoves(heada, headb, mv);
			searchfr(mv);
			(*headb) = (*headb)->next;
			if (head == (*headb))
				break ;
		}
		ajilhnasirilhih(heada, headb, mv);
		pa_push_a(heada, headb, 1);
		size--;
	}
}
