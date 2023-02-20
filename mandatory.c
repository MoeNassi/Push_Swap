/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:52:08 by mnassi            #+#    #+#             */
/*   Updated: 2023/02/20 17:47:02 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps/ft_printf.h"

void	sa_swap_a(t_swap **heada, int i)
{
	int		inde;

	if (ft_lstsize(*heada) < 2)
		return ;
	if (!heada || !*heada)
		return ;
	inde = (*heada)->content;
	(*heada)->content = (*heada)->next->content;
	(*heada)->next->content = inde;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb_swap_b(t_swap **headb, int i)
{
	int		inde;

	if (ft_lstsize(*headb) < 2)
		return ;
	if (!headb || !*headb)
		return ;
	inde = (*headb)->content;
	(*headb)->content = (*headb)->next->content;
	(*headb)->next->content = inde;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss_sa_sb(t_swap **heada, t_swap **headb, int i)
{
	sa_swap_a(heada, 0);
	sb_swap_b(headb, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}

void	pa_push_a(t_swap **heada, t_swap **headb, int i)
{
	t_swap	*del;
	t_swap	*b;

	if (!*headb)
		return ;
	b = (*headb);
	b->prev->next = b->next;
	b->next->prev = b->prev;
	del = b;
	*headb = b->next;
	if (i == 1)
		write(1, "pa\n", 3);
	ft_lstadd_front(heada, ft_lstnew(b->content));
	free(del);
}

void	pb_push_b(t_swap **heada, t_swap **headb, int i)
{
	t_swap	*del;
	t_swap	*a;
	int 	k;

	k = ft_lstsize(*heada);
	if (!*heada)
		return ;
	a = (*heada);
	a->prev->next = a->next;
	a->next->prev = a->prev;
	del = a;
	*heada = a->next;
	if (i == 1)
		write(1, "pb\n", 3);
	ft_lstadd_front(headb, ft_lstnew(a->content));
	if (k == 1)
		heada = NULL;
	else
		free(del);
}
