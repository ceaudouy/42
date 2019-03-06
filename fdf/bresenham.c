/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:41:42 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/03/05 18:26:18 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_octant1(t_struct *all, float e, int k, int i)
{
	e = all->dx;
	all->dx *= 2;
	all->dy *= 2;
	while (all->x1 < all->x2)
	{
		if (all->alt[i][k] > 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, RED);
		else if (all->alt[i][k] < 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, BLU);
		else
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, WHI);
		all->x1++;
		e -= all->dy;
		if (e <= 0)
		{
			all->y1++;
			e += all->dx;
		}
	}
}

void	ft_octant8(t_struct *all, float e, int k, int i)
{
	e = all->dx;
	all->dx *= 2;
	all->dy *= 2;
	while (all->x1 < all->x2)
	{
		if (all->alt[i][k] > 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, RED);
		else if (all->alt[i][k] < 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, BLU);
		else
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, WHI);
		all->x1++;
		e += all->dy;
		if (e <= 0)
		{
			all->y1--;
			e += all->dx;
		}
	}
}

void	ft_octant2(t_struct *all, float e, int k, int i)
{
	e = all->dy;
	all->dy *= 2;
	all->dx *= 2;
	while (all->y1 < all->y2)
	{
		if (all->alt[i][k] > 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, RED);
		else if (all->alt[i][k] < 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, BLU);
		else
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, WHI);
		all->y1++;
		e -= all->dx;
		if (e <= 0)
		{
			all->x1++;
			e += all->dy;
		}
	}
}

void	ft_octant7(t_struct *all, float e, int k, int i)
{
	e = all->dy;
	all->dy *= 2;
	all->dx *= 2;
	while (all->y1 > all->y2)
	{
		if (all->alt[i][k] > 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, RED);
		else if (all->alt[i][k] < 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, BLU);
		else
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, WHI);
		all->y1--;
		e += all->dx;
		if (e > 0)
		{
			all->x1++;
			e += all->dy;
		}
	}
}

void	ft_bresenham(t_struct *all, int i, int k)
{
	float	e;

	e = 0.0;
	all->dx = all->x2 - all->x1;
	all->dy = all->y2 - all->y1;
	if (all->dx > 0)
	{
		if (all->dy > 0)
		{
			if (all->dx >= all->dy)
				ft_octant1(all, e, k, i);
			else
				ft_octant2(all, e, k, i);
		}
		else if (all->dy < 0 && all->dx > 0)
		{
			if (all->dx >= -all->dy)
				ft_octant8(all, e, k, i);
			else
				ft_octant7(all, e, k, i);
		}
		if (all->dy == 0 && all->dx > 0)
			ft_octant_horright(all, i, k);
	}
	ft_bresenham2(all, i, k, e);
}
