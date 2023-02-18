/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:57:25 by mnassi            #+#    #+#             */
/*   Updated: 2023/02/18 16:42:52 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../get-next-line/get_next_line.h"

void	ft_instructions(t_swap *heada, t_swap *headb, char *stock)
{
	if (ft_strncmp(stock, "pa\n", 3))
		pa_push_a(&heada, &headb, 0);
	if (ft_strncmp(stock, "sa\n", 3))
		sa_swap_a(&heada, 0);
	else if (ft_strncmp(stock, "pb\n", 3))
		pb_push_b(&heada, &headb, 0);
	else if (ft_strncmp(stock, "ra\n", 3))
		ra_rotate_a(&heada, 0);
	else if (ft_strncmp(stock, "rra\n", 4))
		rra_reverse_ra(&heada, 0);
	else if (ft_strncmp(stock, "rr\n", 3))
		rr_rotate_ab(&heada, &headb, 0);
	else if (ft_strncmp(stock, "rb\n", 3))
		rb_rotate_b(&headb, 0);
	else if (ft_strncmp(stock, "rrb\n", 4))
		rrb_reverse_rb(&headb, 0);
	else if (ft_strncmp(stock, "sb\n", 3))
		sb_swap_b(&headb, 0);
	else if (ft_strncmp(stock, "ss\n", 3))
		ss_sa_sb(&heada, &headb, 0);
	else if (ft_strncmp(stock, "ra\n", 3))
		ra_rotate_a(&heada, 0);
	else if (ft_strncmp(stock, "rrr\n", 4))
		rrr_reverser(&heada, &headb, 0);
	else
		return((ft_printf("%s\n", "Error"), 0),exit(0));
}

int	okorko(t_swap **heada)
{
	t_swap	*head;
	t_swap	*next;

	head = (*heada);
	while (head)
	{
		next = head->next;
		if (head > next)
			return (0);
		head = head->next;
		if (head == (*heada))
			break ;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*stock;
	char	**st;
	t_swap	*heada;
	t_swap	*head;
	t_swap	*headb;
	int		i;

	i = 0;
	heada = NULL;
	headb = NULL;
	if (ac == 1)
		return (0);
	st = ft_parsing(ac, av);
	while (st[i])
		ft_lstadd_back(&heada, ft_lstnew(ft_atoi(st[i++])));
	stock = get_next_line(0);
	while (stock)
	{
		ft_instructions(heada, headb, stock);
		stock = get_next_line(0);
	}
	if (!okorko(&heada))
		return (ft_printf("%s\n", "KO"), 0);
	return (ft_printf("%s\n", "OK"), 0);
}