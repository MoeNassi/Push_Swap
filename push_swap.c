/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:36:42 by mnassi            #+#    #+#             */
/*   Updated: 2023/02/20 17:25:24 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps/ft_printf.h"

void	ft_fix_check(t_swap **heada)
{
	int		i;

	i = ft_search_sis(heada);
	if (i > (ft_lstsize(*heada) / 2))
		i -= ft_lstsize(*heada);
	while (i > 0)
	{
		ra_rotate_a(heada, 1);
		i--;
	}
	while (i < 0)
	{
		rra_reverse_ra(heada, 1);
		i++;
	}
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

int	main(int ac, char **av)
{
	t_swap	ot;
	t_swap	*heada;
	t_swap	*headb;
	int		i;
	t_move	mv;

	i = 0;
	heada = NULL;
	headb = NULL;
	if (ac < 3)
		return (0);
	ot.za = ft_parsing(ac, av);
	while (ot.za[i])
		ft_lstadd_back(&heada, ft_lstnew(ft_atoi(ot.za[i++])));
	free_tab(ot.za);
	ft_push0tob(&heada, &headb);
	ft_search_forb(&heada, &headb, &mv);
	ft_fix_check(&heada);
	free_list(&heada);
}
