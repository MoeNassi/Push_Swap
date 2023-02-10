/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:36:42 by mnassi            #+#    #+#             */
/*   Updated: 2023/02/10 15:05:04 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps/ft_printf.h"

void	free_tab(char **s)
{
	int		i;

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
	t_swap	*temp;
	int		i;

	i = 0;
	heada = NULL;
	headb = NULL;
	if (ac == 1)
		return (0);
	ot.za = ft_parsing(ac, av);
	while (ot.za[i])
		ft_lstadd_back(&heada, ft_lstnew(ft_atoi(ot.za[i++])));
	free_tab(ot.za);
	ft_push0tob(&heada, &headb);
	ft_best_move(&heada, &headb);
	ft_fix_check(&heada);
	temp = heada;
	while (temp)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
		if (temp == heada)
			break ;
	}
	free_list(&heada);
}
