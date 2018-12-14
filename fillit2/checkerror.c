/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:13:07 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/13 11:39:40 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_checkerror(char *tab)
{
	int		i;
	int		d;
	int		p;

	i = 0;
	d = 0;
	p = 0;
	if (tab[i] == '\n')
		return (1);
	while (tab[i] && (tab[i] == '.' || tab[i] == '#' || tab[i] == '\n'))
	{
		if (tab[i] == '.')
			p++;
		if (tab[i] == '#')
			d++;
		i++;
	}
	if (d == 4 && p == 12 && tab[i - 1] == '\n')
		return (0);
	return (1);
}

static int	ft_check(char *tab, int i)
{
	if (tab[i + 1] == '#')
		i++;
	else if (tab[i + 3] == '#')
		i = i + 3;
	else if (tab[i + 4] == '#')
		i = i + 4;
	else if (tab[i + 5] == '#')
		i = i + 5;
	else
		i = -1;
	return (i);
}

int			ft_check_tetri(char *tab)
{
	int		i;
	int		d;

	i = 0;
	d = 0;
	while (tab[i])
	{
		if (tab[i] == '#')
		{
			d++;
			if (d == 4)
				if (tab[i - 1] == '#' || tab[i - 5] == '#')
					return (0);
			i = ft_check(tab, i);
			if (i == -1)
				return (1);
		}
		else
			i++;
	}
	return (0);
}