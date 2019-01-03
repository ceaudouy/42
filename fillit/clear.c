/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:13:37 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/03 14:37:33 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_clear(char *fgrid, int g)
{
	int		i;
	int		j;
	int		tot;

	tot = ((g + 1) * g);
	i = 0;
	j = 1;
	while (i < tot)
	{
		if ((j % (g + 1)) == 0)
			fgrid[i] = '\n';
		else
			fgrid[i] = '.';
		i++;
		j++;
	}
	fgrid[i] = '\0';
	return (fgrid);
}

char	*ft_print(char *tab, int *info, int xmin, int ymin)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (i < 7) 
	{
		info[i] = info[i] - xmin;
		info[i + 1] = info[i + 1] - ymin; 
		i += 2;
	}
	i = 0;
	while (tab[j]) 
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

char	*ft_clear_tetri(char *tab, int *info, int ymin, int xmin)
{
	int		x;
	int		y;
	int		i;
	//----------------> X = paire || Y = impaire !!!!
	x = 0;
	y = 1;
	i = 0;
	while (tab[i])
	{
		if (tab[i] == '#')
			tab[i] = '.';
		i++;
	}
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
	//printf("xmin = %d || ymin = %d\n", xmin, ymin);
	return (ft_print(tab, info, xmin, ymin));
}
