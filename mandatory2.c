/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:20:43 by mnassi            #+#    #+#             */
/*   Updated: 2023/02/20 11:21:56 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb_reverse_rb(t_swap **headb, int i)
{
	if (ft_lstsize(*headb) < 2)
		return ;
	*headb = (*headb)->prev;
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr_reverser(t_swap **heada, t_swap **headb, int i)
{
	rra_reverse_ra(heada, 0);
	rrb_reverse_rb(headb, 0);
	if (i == 1)
		write(1, "rrr\n", 4);
}
