/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:55:19 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/20 14:53:56 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t				j;
	char				*l;
	unsigned int		o;

	if (!s)
		return (NULL);
	o = ft_strlen(s);
	if (len > o)
		len = o;
	l = malloc(len + 1);
	if (!l)
		return (NULL);
	j = -1;
	while (++j < len && start < o && s[start])
		l[j] = s[start++];
	l[j] = '\0';
	return (l);
}

static int	count(char const *s, char c)
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			counter++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (counter);
}

static void	freesplit(char **s, int i)
{
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**ft_split(char *s, char c)
{
	char	**mok;
	size_t	i;
	size_t	j;
	int		y;

	i = 0;
	j = 0;
	y = -1;
	if (!s)
		return (NULL);
	mok = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!mok)
		return (NULL);
	while (++y < count(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		mok[y] = ft_substr(s, j, i - j);
		if (!mok[y])
			return (freesplit(mok, 0), NULL);
	}
	return (mok[y] = NULL, mok);
}
