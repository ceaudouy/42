/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:02:01 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/16 14:27:22 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_words(char const *s, char c, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && i < len)
		{
			j++;
			while (s[i] != c && i < len)
				i++;
		}
	}
	return (j);
}

static char		*ft_dup(char const *s, int j, int i)
{
	char	*tab;
	int		k;

	k = 0;
	if (!(tab = (char*)malloc(sizeof(*tab) * (i - j) + 1)))
		return (0);
	while (j < i)
	{
		tab[k] = s[j];
		j++;
		k++;
	}
	tab[k] = '\0';
	return (tab);
}

static char		**ft_split(char const *s, char c, char **tab, int len)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		if (s[i] != c && i < len)
		{
			while (s[i] != c && i < len)
				i++;
			tab[k] = ft_dup(s, j, i);
			k++;
		}
		i++;
	}
	tab[k] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		len;
	int		words;
	char	**tab;

	if (s)
	{
		len = ft_strlen((char*)s);
		words = ft_words(s, c, len);
		if (!(tab = (char**)malloc(sizeof(*tab) * words + 1)))
			return (0);
		ft_split(s, c, tab, len);
		return (tab);
	}
	return (0);
}
