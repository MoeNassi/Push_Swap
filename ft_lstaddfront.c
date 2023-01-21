/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:20:57 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/21 15:33:56 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_swap **lst, t_swap *new)
{
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
	}
	else
		*lst = new;
}
