/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:13:07 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/10 17:09:37 by ceaudouy         ###   ########.fr       */
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

static int	ft_link(char *tab, int i)
{
	int		l;

	l = 0;
	if (i > 0 && tab[i - 1] == '#')
		l++;
	if (i < 20 && tab[i + 1] == '#')
		l++;
	if (i >= 5 && tab[i - 5] == '#')
		l++;
	if (i < 15 && tab[i + 5] == '#')
		l++;
	return (l);
}

int			ft_check_tetri(char *tab)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (tab[i])
	{
		if (tab[i] == '#')
		{
			l += ft_link(tab, i);
		}
		i++;
	}
	if (l >= 6)
		return (0);
	else
		return (1);
}

int			ft_check_end(char *tab)
{
	int		j;
	int		n;

	j = 0;
	n = 0;
	while (tab[j])
	{
		if (tab[j] == '\n')
			n++;
		j++;
	}
	if (n != 4)
		return (1);
	return (0);
}
