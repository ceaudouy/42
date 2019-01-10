/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:15:27 by mascorpi          #+#    #+#             */
/*   Updated: 2019/01/09 13:46:23 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		ft_grid(char **tab)
{
	int		i;
	size_t	g;

	i = 1;
	while (tab[i])
		i++;
	i = i - 1;
	g = ft_sqrt(i * 4);
	return (g);
}

void		ft_info(int **info)
{
	int		i;

	i = 0;
	while (i < 28)
	{
		info[i] = 0;
		i++;
	}
}

int			ft_fail(char **tab, size_t i, size_t g, int let)
{
	size_t	start;
	size_t	f;
	int		j;

	f = 0;
	start = 0;
	j = 0;
	if (i == 0)
	{
		free(tab[0]);
		ft_solve(tab, g + 1);
		return (0);
	}
	while (tab[i][j] != '#')
		j++;
	while (tab[0][start] != let)
		start++;
	start += 1 - j;
	while (tab[0][f])
	{
		if (tab[0][f] == let)
			tab[0][f] = '.';
		f++;
	}
	return (start);
}
