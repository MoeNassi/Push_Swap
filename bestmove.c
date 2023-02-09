/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestmove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:22:32 by mnassi            #+#    #+#             */
/*   Updated: 2023/02/09 17:03:38 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	nmb = chr;
	chr = ft_index(heada, nmb);
	countmoves(heada, chr, nmb);
	return (chr);
}

int	ft_search_sis2(t_swap **heada)
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

void	countmoves(t_swap **heada, int ct, int nb)
{
	int		j;
	t_move	mv;
	t_swap	*head;

	j = 0;
	mv.movea = 0;
	head = (*heada);
	while (head)
	{
		if (ct < ft_lstsize(*heada) / 2)
			ra_rotate_a(heada, 1);
		else
			rra_reverse_ra(heada, 1);
		mv.movea++;
		j++;
		head = head->next;
		if (head->content == nb)
			break ;
	}
}

void	ft_fix_check(t_swap **heada)
{
	int	i;

	i = ft_search_sis(heada);
	if (i > ft_lstsize(*heada) / 2)
		i -= ft_lstsize(*heada);
	while(i >= 0)
	{
		ra_rotate_a(heada, 1);
		i--;
	}
	while(i <= 0)
	{
		rra_reverse_ra(heada, 1);
		i++;
	}
}