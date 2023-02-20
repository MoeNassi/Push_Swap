/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:05:09 by mnassi            #+#    #+#             */
/*   Updated: 2023/02/20 17:13:24 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_swap	*tmp;
	t_swap	*tmp_next;

	tmp = *s;
	tmp_next = tmp->next;
	while (tmp_next)
	{
		free(tmp);
		tmp = tmp_next;
		tmp_next = tmp_next->next;
		if (tmp_next->next == *s)
			break ;
	}
}
