/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresemham3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 10:52:07 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/03/02 10:52:08 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_octant_horleft(t_struct *all, int i, int k)
{
    while (all->x1 > all->x2)
    {
        if (all->alt[i][k] > 0)
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16385289);
        else if (all->alt[i][k] < 0)
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 4851194);
        else
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16777215);
        all->x1--;
    }
}

void    ft_octant_vert(t_struct *all, int i, int k)
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
    }
}

void    ft_octant_vert2(t_struct *all, int i, int k)
{
    while (all->y1 > all->y2)
    {
        if (all->alt[i][k] > 0)
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16385289);
        else if (all->alt[i][k] < 0)
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 4851194);
        else
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 16777215);
        all->y1--;
    }
}