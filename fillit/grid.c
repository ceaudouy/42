/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:15:27 by mascorpi          #+#    #+#             */
/*   Updated: 2018/12/13 11:48:18 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_width(char **tab)
{
	int		i;
	int		j;
	int		lenght;

	i = 0;
	lenght = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			while (tab[i][j] == '.')
				j++;
			if (j > 5)
			{
				if (tab[i][j] == '#' && tab[i][j - 5] != '#')
					lenght++;
			}
			else if (tab[i][j] == '#')
				lenght++;
			j++;
		}
		i++;
	}
	return (lenght);
}

static int		ft_high(char **tab)
{
	int		i;
	int		j;
	int		h;

	i = 0;
	h = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
			{
				h++;
				while (tab[i][j] != '\n')
					j++;
			}
			j++;
		}
		i++;
	}
	return (h);
}

int				ft_grid(char **tab)
{
	int h;
	int w;
	int	res;

	w = ft_width(tab);
	h = ft_high(tab);
	res = ft_sqrt(w + h);
	return (res);
}
