/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:41:42 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/27 13:41:44 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_tracerpixel_hordown(t_struct *all, float e, int i, int j)
{
   
    while (all->x1 < all->x2)
    {
        mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16754176);
        all->x1++;
        if ((e = e - all->dy) <= 0)
        {
            all->y1++;
            e += all->dx;
        }
    }
}

void    ft_tracerpixel_horup(t_struct *all, float e, int i, int j)
{
   
    while (all->x1 < all->x2)
    {
        mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16754176);
        all->x1++;
        if ((e = e - all->dy) >= 0)
        {
            all->y1--;
            e += all->dx;
        }
    }
}


void    ft_bresenham(t_struct *all, int i, int j)
{
    float   e;

    all->x1 = all->pos[i][j];
    all->x2 = all->pos[i][j + 2];
    all->y1 = all->pos[i][j + 1];
    all->y2 = all->pos[i][j + 3];
    e = all->pos[i][j + 2] - all->pos[i][j];
    all->dx = e * 2;
    all->dy = (all->pos[i][j + 3] - all->pos[i][j + 1]) * 2;
    if (all->y1 < all->y2)
        ft_tracerpixel_hordown(all, e, i, j); 
    if (all->y1 > all->y2)
        ft_tracerpixel_horup(all, e, i, j);
}
