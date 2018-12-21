/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:31:18 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/21 12:42:40 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
int		ft_checkpos(char *fgrid, char *tab, int f, int g)
{
	int		j;
	int		cnt;

	j = 0;
	cnt = 0;
	while (tab[j] && fgrid[f])
	{
		if (fgrid[f] == '.' && (tab[j] >= 65 && tab[j] <= 90))
			cnt++;
		if (tab[j] == '\n')
			f = (f + g - 4);
		j++;
		f++;
	}
	if (cnt == 4)
		return (0);
	return (1);
}

char	*ft_backtrack(char *fgrid, char **tab, int g, int i, int start)
{
	int			j;
	size_t		f;

	f = start;
	while (tab[i])
	{
		if (f >= ft_strlen(fgrid))
		{
			return (fgrid);
		}
		j = 0;
		while (tab[i][j] == '.' || tab[i][j] == '\n')
			j++;
		while (fgrid[f] != '.' && f < ft_strlen(fgrid))
			f++;
		if ((ft_checkpos(fgrid, &tab[i][j], f, g) == 0))
		{
			while (tab[i][j] && fgrid[f + g - 3])
			{
				if (fgrid[f] == '.' && (tab[i][j] >= 65 && tab[i][j] <= 90))
					fgrid[f] = tab[i][j];
				if (tab[i][j] == '\n')
					f = (f + g - 4);
				f++;
				j++;
			}
			i++;
			f = 0;
		}
		else
			f++;
		if (f >= ft_strlen(fgrid) - 1)
		{
			i--;
			j = 0;
			f = 0;
			start = 0;
			if (i == -1)
			{
				free(fgrid);
				return (ft_solve(tab, g + 1));
			}
			while (tab[i][j] == '.' || tab[i][j] == '\n')
				j++;
			while (fgrid[start] != tab[i][j]) 
				start++; 
			start++;
			while (fgrid[f])
			{
				if (fgrid[f] == tab[i][j])
					fgrid[f] = '.';
				f++;
			}
			return (ft_backtrack(fgrid, tab, g, i, start));
		}
	}
	return (fgrid);
}

char	*ft_solve(char **tab, int g)
{
	int		tot;
	char	*fgrid;
	
	tot = ((g + 1) * g);
	if (!(fgrid = (char *)malloc(sizeof(*fgrid) *(tot + 1))))
		return (NULL);
	fgrid = ft_clear(fgrid, g);
	fgrid = ft_backtrack(fgrid, tab, g, 0, 0);
//		printf("rendu\n%s\n", fgrid);
	return (fgrid);
}
