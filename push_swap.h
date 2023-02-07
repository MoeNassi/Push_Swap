/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:55:46 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/27 15:24:50 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ps/ft_printf.h"

# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_swap
{
	char			**za;
	int				content;
	struct s_swap	*next;
	struct s_swap	*prev;
	int				key;
}				t_swap;

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
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	nospace(char **arguments);
t_swap	*ft_lstnew(int content);
void	ft_lstadd_back(t_swap **lst, t_swap *new);
void	sa_swap_a(t_swap **heada, int i);
void	sb_swap_b(t_swap **headb, int i);
void	ss_sa_sb(t_swap **heada, t_swap **headb);
void	ft_lstadd_front(t_swap **lst, t_swap *new);
void	pa_push_a(t_swap **heada, t_swap **headb);
void	pb_push_b(t_swap **heada, t_swap **headb);
int		ft_lstsize(t_swap *head);
void	ra_rotate_a(t_swap **heada, int i);
void	rb_rotate_b(t_swap **headb , int i);
void	rr_rotate_ab(t_swap	**headb, t_swap **heada);
void	rra_reverse_ra(t_swap **heada, int i);
void	rrb_reverse_rb(t_swap **headb, int i);
void	rrr_reverser(t_swap **heada, t_swap **headb);
int		countlis(t_swap **heada);
int		longestincrseb(t_swap **heada);
void	ft_push0tob(t_swap **heada, t_swap **headb);
void	ft_best_move(t_swap **heada, t_swap **headb);

#endif
