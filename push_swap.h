/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:55:46 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/20 18:42:42 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647

char	**ft_split(char *s, char c);
char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strlen(char *str);
int		ft_isdigit(int c);
void	intchecker(char	**arguments);
void	ft_error(char	*s);
void	intmaxcheck(char **arguments);
long	ft_atoi(const char *str);
char	**ft_parsing(int argc, char **argv);
void	checkdublicate(char	**arguments);

typedef struct	l_push
{
	char	**za;
	void	*content;
	void	*next;
	void	*prev;
}				t_swap;

#endif
