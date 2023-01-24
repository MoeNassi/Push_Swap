/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:56:30 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/24 10:31:10 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_lstsize(t_swap *head)
{
	int		i;
	t_swap	*last;

	if (!head)
		return (0);
	i = 0;
	last = head;
	while (1)
	{
		i++;
		last = last->next;
		if(last == head)
			break;
	}
	return (i);
}