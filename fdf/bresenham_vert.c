/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_vert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:27:44 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/27 15:27:45 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_octant4(t_struct *all, float e, int k, int i)
{
    e = all->dx;
    all->dx *= 2;
    all->dy *= 2;
    while (all->x1 > all->x2)
    {
        if (all->alt[i][k] > 0)
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16385289);
        else if (all->alt[i][k] < 0)
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 4851194);
        else
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16777215);
        all->x1--;
        e += all->dy;
        if (e >= 0)
        {
            all->y1++;
            e += all->dx;
        }
    }
}

void    ft_octant3(t_struct *all, float e, int k, int i)
{
    e = all->dy;
    all->dx *= 2;
    all->dy *= 2;
    while (all->y1 < all->y2)
    {
        if (all->alt[i][k] > 0)
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16385289);
        else if (all->alt[i][k] < 0)
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 4851194);
        else
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16777215);
        all->y1++;
        e += all->dx;
        if (e <= 0)
        {
            all->x1--;
            e += all->dy;
        }
    }
}

void    ft_octant5(t_struct *all, float e, int k, int i)
{
    e = all->dx;
    all->dx *= 2;
    all->dy *= 2;
    while (all->x1 > all->x2)
    {
       if (all->alt[i][k] > 0)
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16385289);
        else if (all->alt[i][k] < 0)
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 4851194);
        else
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16777215);
        all->x1--;
        e -= all->dy;
        if (e >= 0)
        {
            all->y1--;
            e += all->dx;
        }
    }
}

void    ft_octant6(t_struct *all, float e, int k, int i)
{
    e = all->dy;
    all->dx *= 2;
    all->dy *= 2;
    while (all->y1 > all->y2)
    {
        if (all->alt[i][k] > 0)
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16385289);
        else if (all->alt[i][k] < 0)
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 4851194);
        else
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16777215);
        all->y1--;
        e -= all->dx;
        if (e >= 0)
        {
            all->x1--;
            e += all->dy;
        }
    }
}