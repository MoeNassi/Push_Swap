/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:36:42 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/23 16:07:45 by mnassi           ###   ########.fr       */
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
	// t_swap	*tempp;
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
	while (heada)
	{
		ft_printf("before : %d\n", heada->content);
		heada = heada->next;
		if (heada == temp)
			break ;
	}
	puts("A");
	pb_push_b(&heada,&headb);
	ft_printf("----%d\n",headb->content);
	puts("B");
	
	pb_push_b(&heada,&headb);
	ft_printf("----%d\n",headb->content);
	ft_printf("----%d\n",headb->next->content);
	ft_printf("----%d\n",headb->next->next->content);

	// rb_rotate_b(&headb,1);
	temp = headb;
	puts("C");
	// while (headb)
	// {
	// 	ft_printf("after : %d|%d|%d\n",headb->prev->content ,headb->content , headb->next->content);
		
	// 	headb = headb->next;
	// 	if (headb == temp)
	// 		break ;
	// }
	// pb_push_b(&heada, &headb);
	// tempp = heada;
	// while (heada)
	// {
	// 	ft_printf("B : %d\n", heada->content);
	// 	heada = heada->next;
	// 	if (heada == tempp)
	// 		break ;
	// }
	// pa_push_a(&heada, &headb);
	// tempp = heada;
	// while (heada)
	// {
	// 	ft_printf("A : %d\n", heada->content);
	// 	heada = heada->next;
	// 	if (heada == tempp)
	// 		break ;
	// }
	free_list(&heada);
}
