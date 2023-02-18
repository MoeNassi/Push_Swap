/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thebestofthebest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:23:25 by mnassi            #+#    #+#             */
/*   Updated: 2023/02/18 15:21:02 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int i)
{
	if (i < 0)
		return (i * (-1));
	return (i);
}

void	whosbetter(t_move *mv)
{
	int		stock;

	if (ft_abs(mv->movea) >= ft_abs(mv->moveb))
		stock = ft_abs(mv->movea);
	else
		stock = ft_abs(mv->moveb);
	if (stock <= mv->total)
	{
		mv->total = stock;
		mv->bestmovea = mv->movea;
		mv->bestmoveb = mv->moveb;
	}
}

void	ajilhnasirilhih(t_swap **heada, t_swap **headb, t_move *mv)
{
	while (mv->bestmovea > 0 && mv->bestmoveb > 0)
	{
		rr_rotate_ab(heada, headb, 1);
		mv->bestmovea--;
		mv->bestmoveb--;
	}
	while (mv->bestmovea < 0 && mv->bestmoveb < 0)
	{
		rrr_reverser(heada, headb, 1);
		mv->bestmovea++;
		mv->bestmoveb++;
	}
	while (mv->bestmovea > 0)
	{
		ra_rotate_a(heada, 1);
		mv->bestmovea--;
	}
	while (mv->bestmovea < 0)
	{
		rra_reverse_ra(heada, 1);
		mv->bestmovea++;
	}
	while (mv->bestmoveb > 0)
	{
		rb_rotate_b(headb, 1);
		mv->bestmoveb--;
	}
	while (mv->bestmoveb < 0)
	{
		rrb_reverse_rb(headb, 1);
		mv->bestmoveb++;
	}
}

void	checkmoves(t_swap **heada, t_swap **headb, t_move *mv)
{
	if (mv->movea > (ft_lstsize(*heada) / 2))
		mv->movea -= ft_lstsize(*heada);
	if (mv->moveb > (ft_lstsize(*headb) / 2))
		mv->moveb -= ft_lstsize(*headb);
}