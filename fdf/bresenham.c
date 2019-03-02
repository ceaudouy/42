/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:41:42 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/03/02 14:52:58 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_octant1(t_struct *all, float e, int k, int i)
{
	e = all->dx;
	all->dx *= 2;
	all->dy *= 2;
	while (all->x1 < all->x2)
	{
		if (all->alt[i][k] > 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16385289);
		else if (all->alt[i][k] < 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 4851194);
		else
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16777215);
		all->x1++;
		e -= all->dy;
		if (e <= 0)
		{
			all->y1++;
			e += all->dx;
		}
	}
}

void    ft_octant8(t_struct *all, float e, int k, int i)
{
	e = all->dx;
	all->dx *= 2;
	all->dy *= 2;
	while (all->x1 < all->x2)
	{
		if (all->alt[i][k] > 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16385289);
		else if (all->alt[i][k] < 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 4851194);
		else
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16777215);
		all->x1++;
		e += all->dy;
		if (e <= 0)
		{
			all->y1--;
			e += all->dx;
		}
	}
}

void    ft_octant2(t_struct *all, float e, int k, int i)
{
	e = all->dy;
	all->dy *= 2;
	all->dx *= 2;
	while (all->y1 < all->y2)
	{
		if (all->alt[i][k] > 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16385289);
		else if (all->alt[i][k] < 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 4851194);
		else
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16777215);
		all->y1++;
		e -= all->dx;
		if (e <= 0)
		{
			all->x1++;
			e += all->dy;
		}
	}
}

void    ft_octant7(t_struct *all, float e, int k, int i)
{
	e = all->dy;
	all->dy *= 2;
	all->dx *= 2;
	while (all->y1 > all->y2)
	{
		if (all->alt[i][k] > 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16385289);
		else if (all->alt[i][k] < 0)
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 4851194);
		else
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16777215);
		all->y1--;
		e += all->dx;
		if (e > 0)
		{
			all->x1++;
			e += all->dy;
		}
	}
}

void    ft_bresenham(t_struct *all, int i, int j, int k)
{
	float   e;
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
		{
			while (all->x1 < all->x2)
			{
				if (all->alt[i][k] > 0)
					mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16385289);
				else if (all->alt[i][k] < 0)
					mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 4851194);
				else
					mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16777215);
				all->x1++;
			}
		}
	}
	else if (all->dx < 0)
	{
		if (all->dy > 0)
		{
			if (-all->dx >= all->dy)
				ft_octant4(all, e, k, i);
			else
				ft_octant3(all, e, k, i);
		}
		if (all->dy < 0 && all->dx < 0)
		{
			if (all->dx <= all->dy)
				ft_octant5(all, e, k, i);
			else
				ft_octant6(all, e, k, i);        
		}
		if (all->dy == 0 && all->dx < 0)
			ft_octant_horleft(all, i, k);
	}
	if (all->dx == 0)
	{
		if (all->dy > 0)
			ft_octant_vert(all, i, k);
	}
	if (all->dy < 0 && all->dx == 0)
ft_octant_vert2(all, i, k);
}
