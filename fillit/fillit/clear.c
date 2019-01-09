/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:13:37 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/09 14:02:24 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_clear(char **tab, size_t g)
{
	size_t	i;
	size_t	j;
	size_t	tot;

	tot = ((g + 1) * g);
	i = 0;
	j = 1;
	while (i < tot)
	{
		if ((j % (g + 1)) == 0)
			tab[0][i] = '\n';
		else
			tab[0][i] = '.';
		i++;
		j++;
	}
	tab[0][i] = 0;
	return (tab);
}

static char	*ft_tab_clear(char *tab, int *info, int i)
{
	int		j;
	int		x;
	int		y;

	j = 0;
	x = 0;
	y = 0;
	while (tab[j] && i < 8)
	{
		if (x == info[i] && y == info[i + 1])
		{
			tab[x + 5 * y] = '#';
			i += 2;
		}
		if (tab[j] == '.')
			x++;
		if (tab[j] == '\n')
		{
			y++;
			x = 0;
		}
		j++;
	}
	return (tab);
}

static char	*ft_print(char *tab, int *info, int xmin, int ymin)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		info[i] = info[i] - xmin;
		info[i + 1] = info[i + 1] - ymin;
		i += 2;
	}
	return (ft_tab_clear(tab, info, 0));
}

char		*ft_clear_tetri(char *tab, int *info, int ymin, int xmin)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 1;
	i = 0;
	while (tab[i])
		if (tab[i] == '#')
			tab[i] = '.';
		else
			i++;
	while (y < 8)
	{
		if (info[y] < ymin)
			ymin = info[y];
		y = y + 2;
	}
	while (x < 7)
	{
		if (info[x] < xmin)
			xmin = info[x];
		x = x + 2;
	}
	return (ft_print(tab, info, xmin, ymin));
}
