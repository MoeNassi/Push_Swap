/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:55:00 by mnassi            #+#    #+#             */
/*   Updated: 2023/02/20 16:02:40 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rotate_a(t_swap **heada, int i)
{
	if (ft_lstsize(*heada) < 2)
		return ;
	*heada = (*heada)->next;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb_rotate_b(t_swap **headb, int i)
{
	if (ft_lstsize(*headb) < 2)
		return ;
	(*headb) = (*headb)->next;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr_rotate_ab(t_swap	**heada, t_swap **headb, int i)
{
	ra_rotate_a(heada, 0);
	rb_rotate_b(headb, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}

void	rra_reverse_ra(t_swap **heada, int i)
{
	if (ft_lstsize(*heada) < 2)
		return ;
	*heada = (*heada)->prev;
	if (i == 1)
		write(1, "rra\n", 4);
}
