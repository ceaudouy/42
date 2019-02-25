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

    i = 0;
    while (i < all->y - 1 )
    {
        k = 1;
        while (k < ft_strlen(all->map[i]))
        {
            if (all->pos[i][k - 1] == all->pos[i + 1][k - 1])
            {
                draw = all->pos[i][k];
                while (draw < all->pos[i + 1][k])
                {
                    mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->pos[i][k - 1], draw, 0xFF0000);
                    draw++;
                }
            }
            k += 2;
        }
        i++;
    }
    /*
    int     k;
    int     draw;
    int     i;

    i = 0;
    while (k < all->size)
    {
        if (all->pos[k] == all->pos[k + 2])
        {
            draw = all->pos[i][k + 1];
            while (draw < all->pos[k + 2])
            {
                mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->pos[k], draw, 0xFF0000);
                draw++;
            }
        }
        k += 2;
    }*/
}

void    ft_draw(t_struct *all)
{
    size_t    k;
    int    draw;
    int    i;

    i = 0;
    while (i < all->y)
    {
        k = 0;
        while (k < ft_strlen(all->map[i]))
        {
            if (all->pos[i][k + 1] == all->pos[i][k + 3])
            {
                draw = all->pos[i][k];
                while (draw < all->pos[i][k + 2])
                {
                    mlx_pixel_put(all->mlx_ptr, all->win_ptr, draw, all->pos[i][k + 1], 0xFF0000);
                    draw++;
                }
            }
            k += 2;
        }
        i++;
    }    
    draw_vert(all);
}