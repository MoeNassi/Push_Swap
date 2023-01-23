/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:53:30 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/22 11:44:24 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_swap **lst, t_swap *new)
{
	t_swap	*head;
	t_swap	*nex;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	head = (*lst);
	nex = (*lst);
	while (nex->next != head)
		nex = nex->next;
	nex->next = new;
	new->next = head;
	new->prev = nex;
	head->prev = new;
}
