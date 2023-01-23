/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:36:42 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/23 17:37:27 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps/ft_printf.h"

void	free_tab(char **s)
{
	int i;
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	free_list(t_swap **s)
{
	t_swap *tmp;
	t_swap *tmp_next;
	
	tmp = *s;
	tmp_next = tmp->next; 
	while (1)
	{
		free(tmp);
		tmp = tmp_next;
		tmp_next = tmp_next->next;
		if(tmp_next->next == *s)
			break;
	}
}
int	main(int ac, char **av)
{
	t_swap	ot;
	t_swap	*heada;
	t_swap	*headb;
	t_swap	*tempp;
	t_swap	*temp;
	int		i;

	i = 0;
	heada = NULL;
	headb = NULL;
	if (ac == 1)
		return (ft_error("No Argument Detected"), 0);
	ot.za = ft_parsing(ac, av);
	while (ot.za[i])
		ft_lstadd_back(&heada, ft_lstnew(ft_atoi(ot.za[i++])));
	free_tab(ot.za);
	temp = heada;
	while (1)
	{
		ft_printf("before : %d\n", temp->content);
		temp = temp->next;
		if (heada == temp)
			break ;
	}
	// rb_rotate_b(&headb,1);
	temp = headb;
	// while (headb)
	// {
	// 	ft_printf("after : %d|%d|%d\n",headb->prev->content ,headb->content , headb->next->content);
		
	// 	headb = headb->next;
	// 	if (headb == temp)
	// 		break ;
	// }
	// rra_reverse_ra(&heada, 1);
	pb_push_b(&heada,&headb);
	pb_push_b(&heada,&headb);
	tempp = headb;
	while (1)
	{
		ft_printf("A : %d\n", tempp->content);
		tempp = tempp->next;
		if (headb == tempp)
			break ;
	}
	free_list(&heada);
}
