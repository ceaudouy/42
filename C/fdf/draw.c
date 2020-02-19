/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:01:07 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/03/05 18:23:55 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_vert(t_struct *all)
{
	int		k;
	int		i;
	int		j;

	i = 0;
	while (i < all->y - 1)
	{
		k = 0;
		j = 0;
		while (k < all->size[i] * 2)
		{
			if (k / 2 < all->size[i + 1])
			{
				all->x1 = all->pos[i][k];
				all->y1 = all->pos[i][k + 1];
				all->x2 = all->pos[i + 1][k];
				all->y2 = all->pos[i + 1][k + 1];
			}
			ft_bresenham(all, i, j);
			k += 2;
			j++;
		}
		i++;
	}
}

void	ft_draw(t_struct *all)
{
	int		k;
	int		i;
	int		j;

	i = 0;
	while (i < all->y)
	{
		k = 0;
		j = 0;
		while (k < all->size[i] * 2 - 2)
		{
			all->x1 = all->pos[i][k];
			all->y1 = all->pos[i][k + 1];
			all->x2 = all->pos[i][k + 2];
			all->y2 = all->pos[i][k + 3];
			ft_bresenham(all, i, j);
			k += 2;
			j++;
		}
		i++;
	}
	draw_vert(all);
}
