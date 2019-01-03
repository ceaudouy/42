/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:31:18 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/30 11:44:43 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_checkpos(char *fgrid, char **tab, size_t f, int g)
{
	int			j;
	int			cnt;

	j = 0;
	cnt = 0;
	while (tab[1][j] == '.' || tab[1][j] == '\n')
		j++;
	while (tab[1][j] && (f < (ft_strlen(tab[0]) - 1)))
	{
		if (tab[1][j] >= 65 && tab[1][j] <= 90)
			if (tab[0][f] == '.')
				cnt++;
		if (tab[1][j] == '\n')
				f = (f + g - 4);
		f++;
		j++;
	}
	if (cnt == 4)
		return (0);
	puts("fsfhusdf");
	return (1);
}

char	*ft_backtrack(char **tab, int g, int i, size_t start)
{
	size_t		j;
	size_t		f;
	int			cnt;

	f = start;
	while (tab[i])
	{
		cnt = 0;
		j = 0;
		while (tab[i][j] == '.' || tab[i][j] == '\n')
			j++;
		while (tab[0][f] != '.' && f < ft_strlen(tab[0]))
			f++;
		if ((!(tab[i][j] == '\0')) && (ft_checkpos(tab[0], &tab[i], f, g) == 0))
		{
			while (cnt < 4)
			{
				if (tab[0][f] == '.' && (tab[i][j] >= 65 && tab[i][j] <= 90))
				{
					tab[0][f] = tab[i][j];
					cnt++;
				}
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
		if (f >= ft_strlen(tab[0]) - 1)
		{
			i--;
			j = 0;
			f = 0;
			start = 0;
			if (i == 0)
			{
				free(tab[0]);
				return (ft_solve(tab, g + 1));
			}
			while (tab[i][j] == '.' || tab[i][j] == '\n')
				j++;
			while (tab[0][start] != tab[i][j] && tab[0][start]) 
				start++; 
			start++;
			if (start >= ft_strlen(tab[0]) )
			{
				free(tab[0]);
				return (ft_solve(tab, g + 1));
			}
			while (tab[0][f])
			{
				if (tab[0][f] == tab[i][j])
					tab[0][f] = '.';
				f++;
			}
			return (ft_backtrack(tab, g, i, start));
		}
	}
	return (tab[0]);
}

char	*ft_solve(char **tab, int g)
{
	int		tot;
	
	tot = ((g + 1) * g);
	printf("g = %d\n", g);
	if (!(tab[0] = (char*)malloc(sizeof(char) * tot + 1)))
		return (NULL);
	tab[0] = ft_clear(tab[0], g);
	printf("%s\n", tab[0]);
	tab[0] = ft_backtrack(tab, g, 1, 0);
	return (tab[0]);
}
