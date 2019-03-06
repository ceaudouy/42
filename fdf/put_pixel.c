/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:21:55 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/03/05 19:03:06 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pos2(t_struct *all, int i, int x, int y)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (j < all->size[i] * 2)
	{
		all->pos[i][j] = (x + 0.5 + (-all->alt[i][k]
					* all->coef)) + all->posx;
		all->pos[i][j + 1] = y + (0.5 / 2) * (-all->alt[i][k]
				* all->coef) + all->posy;
		j += 2;
		k++;
		x += (1000 / all->y) / 2;
	}
}

void	ft_pos(t_struct *all)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 150;
	if (!(all->pos = (int**)malloc(sizeof(*all->pos) * all->y)))
		exit(1);
	while (i < all->y)
	{
		x = 150;
		if (!(all->pos[i] = (int*)malloc(sizeof(*all->pos[i])
						* all->size[i] * 2)))
			exit(1);
		ft_pos2(all, i, x, y);
		i++;
		y += (1000 / all->y) / 2;
	}
}
