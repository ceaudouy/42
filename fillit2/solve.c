/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:31:18 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/14 18:10:43 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkpos(char *fgrid, char *tab, int f, int g)
{
	int		j;
	int		cnt;

	j = 0;
	cnt = 0;
	while (tab[j])
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
	int		j;
	int		f;

			printf("start = %d\n", start);
			printf("i = %d\n", i);
	f = start;
	while (tab[i])
	{
	
	printf("tab[i] = \n%s\n", tab[i]);
	printf("%s\n", fgrid);
			printf("f = %d\n", f);
		j = 0;
		while (tab[i][j] == '.' || tab[i][j] == '\n')
			j++;
		while (fgrid[f] != '.')
			f++;
			printf("f = %d\n", f);
		if ((ft_checkpos(fgrid, &tab[i][j], f, g) == 0))
		{
			while (tab[i][j])
			{
				if (fgrid[f] == '.' && (tab[i][j] >= 65 && tab[i][j] <= 90))
					fgrid[f] = tab[i][j];
				if (tab[i][j] == '\n')
					f = (f + g - 4);
				f++;
				j++;
			}
			printf("j = %d\n", j);
			i++;
			f = 0;
		}
		else
			f++;
		if (f == ft_strlen(fgrid) - 1)
		{
			i--;
			j = 0;
			f = 0;
			start = 0;
			while (tab[i][j] == '.' || tab[i][j] == '\n') // caractere recheche
				j++;
			while (fgrid[start] != tab[i][j]) // derniere position commence
				start++; 
			start++; // pos + 1
			while (fgrid[f]) //dell caractere voulu
			{
				if (fgrid[f] == tab[i][j])
					fgrid[f] = '.';
				f++;
			}
	printf("%s\n", fgrid);
			puts("backtak");
			ft_backtrack(fgrid, tab, g, i, start);
		}
	}
	return (fgrid);
}

char	*ft_solve(char **tab)
{
	int		tot;
	char	*fgrid;
	int		g;
	int		max;

	max = 0;
	while (tab[max])
		max++;
	g = ft_sqrt(max * 4);
	tot = ((g + 1) * g);
	if (!(fgrid = (char *)malloc(sizeof(*fgrid) *(tot + 1))))
		return (NULL);
	ft_clear(fgrid, g);
	if (!(ft_backtrack(fgrid, tab, g, 0, 0)))
		return (NULL);		
	printf("%s\n", fgrid);
	return (fgrid);
}
