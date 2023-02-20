/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:56:30 by mnassi            #+#    #+#             */
/*   Updated: 2023/02/20 11:28:12 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_swap *head)
{
	t_swap	*last;
	int		i;

	if (!head)
		return (0);
	i = 0;
	last = head;
	while (1)
	{
		last = last->next;
		i++;
		if (last == head)
			break ;
	}
	return (i);
}
