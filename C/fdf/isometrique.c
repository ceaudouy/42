/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometrique.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 11:10:25 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/03/06 11:05:12 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso2(t_struct *all, int i, int x, int y)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (j < all->size[i] * 2)
	{
		all->pos[i][j] = (0.5 * x - 0.5 * y) + all->posx;
		all->pos[i][j + 1] = ((-all->alt[i][k] * all->coef) + 0.5 / 2
				* x + 0.7 / 2 * y) + all->posy;
		j += 2;
		k++;
		x += (1000 / all->y) / 1.2;
	}
}

void	isometrique(t_struct *all)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 40;
	if (!(all->pos = (int**)malloc(sizeof(*all->pos) * all->y)))
		exit(1);
	while (i < all->y)
	{
		x = 1300;
		if (!(all->pos[i] = (int*)malloc(sizeof(*all->pos[i])
						* all->size[i] * 2)))
			exit(1);
		iso2(all, i, x, y);
		i++;
		y += (1000 / all->y) / 1.2;
	}
}
