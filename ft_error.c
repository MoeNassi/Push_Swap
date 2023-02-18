/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:29:40 by mnassi            #+#    #+#             */
/*   Updated: 2023/02/18 11:07:04 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps/ft_printf.h"
#include "push_swap.h"

void	ft_error(char	*s)
{
	ft_printf("%s\n", s);
	exit(0);
}
