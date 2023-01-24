/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:22:24 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/24 12:12:08 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	*ft_lstnew(int content)
{
	t_swap	*new;

	new = malloc(sizeof(t_swap));
	new->content = content;
	new->key = 0;
	new->next = new;
	new->prev = new;
	return (new);
}
