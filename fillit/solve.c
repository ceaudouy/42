/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:09:14 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/13 18:11:18 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_checkpos(char *tab, char *fgrid, int f)
{
	int j;
	int cnt;

	j = 0;
	cnt = 0;

	while (tab[j])
	{
		if (fgrid[f] == '.' && tab[j] >= 65 && tab[j] <= 90)
			cnt++;
	printf("%d\n", cnt);
	printf("fgrid =%c\n", fgrid[f]);
	printf("tab =%c\n", tab[j]);
		if (fgrid[f] == '\n')
			while (tab[j] == '\n' || tab[j] == '.')
				j++;
		j++;
		f++;
	}
	if (cnt == 4)
		return (0);
	return (1);

}

int		ft_checkfinal(char *fgrid, char **tab)
{
	int		i;
	int		nb_tetri;
	int		cnt;

	i = 0;
	nb_tetri = 0;
	cnt = 0;
	while (tab[nb_tetri])
		nb_tetri++;
	while (fgrid[i])
	{
		if (fgrid[i] >= 65 && fgrid[i] <= 90)
			cnt++;
		i++;
	}
	if (cnt == (nb_tetri * 4))
		return (0);
	return (1);
}

static char	*ft_backtrack(char *fgrid, char **tab, int i, int g, int start)
{
	int		j;
	int		f;

	f = start;
	while (tab[i])
	{
		j = 0;
		while (fgrid[f])
		{
			while ((fgrid[f] >= 65 && fgrid[f] <= 90) || fgrid[f] == '\n')
				f++;
			while (tab[i][j] == '.' || tab[i][j] == '\n')
				j++;
			if (ft_checkpos(&tab[i][j], fgrid, f) == 0)
			{
				while (tab[i][j])
				{
					if (fgrid[f] == '.' && tab[i][j] >= 65 && tab[i][j] <= 90)
						fgrid[f] = tab[i][j];
					f++;
					j++;
				}
			}
			else if (f == g)
			{
				ft_backtrack(fgrid, tab, i--, g, start + 1); 
			}
			else	
				f++;
		}
		i++;
		f = 0;
	}
	if (start > ((g + 1) * g))
		return(0);
	if (!tab[i])
		return(0);
	if ((ft_checkfinal(fgrid, tab)) == 1)
	{
		ft_clear(fgrid, g);
		ft_backtrack(fgrid, tab, 0, g, (start + 1));
	}
	return (fgrid);
}

char	*ft_solve(char **tab, int g)
{
	int		i;
	int		j;
	int		tot;
	char	*fgrid;

	i = 0;
	j = 1;
	//g--; // pour avoir un tableu de -1 pour tester tab min
	tot = ((g + 1) * g);
	if (!(fgrid = (char *)malloc(sizeof(*fgrid) * (tot + 1))))
		return (NULL);
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
	ft_backtrack(fgrid, tab, 0, g, 0);
	//if (ft_checkimpossible = 0)
	//	ft_solve(tab, g + 1);
	return (fgrid);
}
