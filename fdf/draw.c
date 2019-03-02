/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:01:07 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/22 13:01:09 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void    draw_vert(t_struct *all)
{
    size_t    k;
    int    draw;
    int    i;
    int     j;
    i = 0;
    while (i < all->y - 1)
    {
        k = 0;
        j = 0;
        while (k < all->size[i] * 2)
        {
            all->x1 = all->pos[i][k];
            all->y1 = all->pos[i][k + 1];
            all->x2 = all->pos[i + 1][k];
            all->y2 = all->pos[i + 1][k + 1];
            all->dx = all->x2 - all->x1;
            all->dy = all->y2 - all->y1;
            ft_bresenham(all, i, k, j);
            k += 2;
            j++;            
        }
        i++;
    }
}

void    ft_draw(t_struct *all)
{

    
    size_t    k;
    int    draw;
    int    i;
    int    j;

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
            all->dx = all->x2 - all->x1;
            all->dy = all->y2 - all->y1;
            ft_bresenham(all, i, k, j);
            k += 2;
            j++;            
        }
        i++;
    }
    draw_vert(all);
}