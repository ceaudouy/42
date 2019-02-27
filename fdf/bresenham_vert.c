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
    while (all->y1 > all->y2)
    {
        mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16777215);
        all->y1++;
        if ((e = e - all->dx) >= 0)
        {
            all->x1--;
            e += all->dy;
        }
    }
}

void       ft_tracerpixel_vertright(t_struct *all, float e, int i, int j)
{
    while (all->y1 < all->y2)
    {
        mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16777215);
        all->y1++;
        if ((e = e - all->dx) <= 0)
        {
            all->x1++;
            e += all->dy;
        }
    }
}

void    ft_bresenham_vert(t_struct *all, int i, int j)
{
    float   e;

    all->x1 = all->pos[i][j];
    all->x2 = all->pos[i][j + 2];
    all->y1 = all->pos[i][j + 1];
    all->y2 = all->pos[i][j + 3];
    e = all->pos[i][j + 3] - all->pos[i][j + 1];
    all->dx = (all->pos[i][j + 2] - all->pos[i][j]) * 2;
    all->dy = e * 2;
    if (all->x1 < all->x2)
        ft_tracerpixel_vertright(all, e, i, j);
    if (all->x1 > all->x2)
        ft_tracerpixel_vertleft(all, e, i, j);
    
}