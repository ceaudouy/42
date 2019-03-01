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

void       ft_tracerpixel_vertleft(t_struct *all, float e, int i, int j, int k)
{
    printf("dx = %d\n", all->dx);
    printf("dy = %d\n", all->dy);
    printf("e = %d\n", e);
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
            all->y1++;
            e += all->dx;
        }
    }
}

void       ft_tracerpixel_vertright(t_struct *all, float e, int i, int j, int k)
{
    while (all->y1 < all->y2)
    {
        if (all->alt[i][k] > 0)
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16385289);
        else if (all->alt[i][k] < 0)
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 4851194);
        else
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16777215);
        all->y1++;
        if ((e = e - all->dy) <= 0)
        {
            all->x1++;
            e += all->dx;
        }
    }
}

void    ft_bresenham_vert(t_struct *all, int i, int j, int k)
{
    float   e;
    
    j--;
    all->x1 = all->pos[i][j];
    all->y1 = all->pos[i][j + 1];
    all->x2 = all->pos[i + 1][j];
    all->y2 = all->pos[i + 1][j + 1];
    all->dy = (all->y1 - all->y2) * 2;
    all->dx = (all->x2 - all->x1) * 2;
    e = all->x2 - all->x1;
    if (all->x1 < all->x2 && all->y1 < all->y2)
        ft_tracerpixel_vertright(all, e, i, j, k);
    if (all->x1 > all->x2 && all->y1 < all->y2)
        ft_tracerpixel_vertleft(all, e, i, j, k);
}
