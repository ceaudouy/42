/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:13:07 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/10 16:34:30 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkerror(char *tab)
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
	if ((ft_strlen(tab) == i && d == 4 && p == 12 && tab[i - 1] == '\n'))
		return (0);
	return (1);
}
