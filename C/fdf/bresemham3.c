/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresemham3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 10:52:07 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/03/05 18:13:57 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_octant_horleft(t_struct *all, int i, int k)
{
	while (all->x1 > all->x2)
	{
		if (all->alt[i][k] > 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, RED);
		else if (all->alt[i][k] < 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, BLU);
		else
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, WHI);
		all->x1--;
	}
}

void	ft_octant_vert(t_struct *all, int i, int k)
{
	while (all->y1 < all->y2)
	{
		if (all->alt[i][k] > 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, RED);
		else if (all->alt[i][k] < 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, BLU);
		else
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, WHI);
		all->y1++;
	}
}

void	ft_octant_vert2(t_struct *all, int i, int k)
{
	while (all->y1 > all->y2)
	{
		if (all->alt[i][k] > 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, RED);
		else if (all->alt[i][k] < 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, BLU);
		else
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, WHI);
		all->y1--;
	}
}

void	ft_octant_horright(t_struct *all, int i, int k)
{
	while (all->x1 < all->x2)
	{
		if (all->alt[i][k] > 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, RED);
		else if (all->alt[i][k] < 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, BLU);
		else
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, WHI);
		all->x1++;
	}
}
