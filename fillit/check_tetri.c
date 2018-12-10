/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:59:47 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/10 15:46:48 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
   int		ft_check_tetri_diag(char *tab)
   {
   int		i;
   int		j;

   i = 0;
   while (tab[i])
   {
   if (tab[i] == '#')
   {
   j = 0;
   while (tab[i + 5] && j < 6)
   {
   j++;
   i++;
   if (tab[i] == '#')
   break;
   if ((j == 6) && (tab[i] =='\n'))
   return (1);
   }
   if (j > 6)
   return (1);
   }
   i++;
   }
   return (0);
   }
   */
/*int		ft_check_tetri_diag(char *tab)
{
	int		i;
	int		next;
	int		d;

	i = 0;
	d = 0;
	while (tab[i])
	{
		next = 2;
		if (tab[i] == '#')
		{
			d++;
			if (tab[i + 1] == '#')
			{
				i++;
				d++;
			}
			else
			{
				while (next <= 5)
				{
					if (tab[i + next] == '#')
					{
					//	if (tab[i + next - 5] != '#')
					//		return (1);
						;
					}
					next++;
				}
				if (next > 5)
					return (1);
			}
		}
		i++;
	}
	return (0);
}*/

int		ft_check_tetri_diag(char *tab)
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
			{
				if (tab[i - 1] == '#' || tab[i - 5] == '#')
					return (0);
				else
					return (1);
			}
			if (tab[i + 1] == '#')
				i++;
			else if (tab[i + 3] == '#')
				i = i + 3;
			else if (tab[i + 4] == '#')
				i = i + 4;
			else if (tab[i + 5] == '#')
				i = i + 5;
			else
				return (1);
		}
		else
			i++;
	}
	return (0);
}

