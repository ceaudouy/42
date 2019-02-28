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

void       ft_tracerpixel_vertleft(t_struct *all, float e, int i, int j)
{
    while (all->y1 < all->y2)
    {
        mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16754176);
        all->y1++;
        if ((e = e - all->dy) >= 0)
        {
            all->x1--;
            e += all->dx;
        }
    }
}

void       ft_tracerpixel_vertright(t_struct *all, float e, int i, int j)
{
    while (all->y1 < all->y2)
    {
        mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16754176);
        all->y1++;
        if ((e = e - all->dy) <= 0)
        {
            all->x1++;
            e += all->dx;
        }
    }
}

void    ft_bresenham_vert(t_struct *all, int i, int j)
{
    float   e;
    
    j--;
    all->x1 = all->pos[i][j];
    all->y1 = all->pos[i][j + 1];
    all->x2 = all->pos[i + 1][j];
    all->y2 = all->pos[i + 1][j + 1];
    e = all->y2 - all->y1;
    all->dx = e * 2;
    all->dy = (all->x2 - all->x1) * 2;
    if (all->x1 < all->x2)
        ft_tracerpixel_vertright(all, e, i, j);
    if (all->x1 > all->x2)
        ft_tracerpixel_vertleft(all, e, i, j);
     //if (all->x1 < all->x2 && all->y1 > all->y2)
       // ft_tracerpixel_vertright(all, e, i, j);
}
