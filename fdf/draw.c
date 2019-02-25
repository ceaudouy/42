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
    int     k;
    int     draw;

    k = 0;
    while (k < all->size)
    {
        if (all->pos[k] == all->pos[k + 2])
        {
            draw = all->pos[k + 1];
            while (draw < all->pos[k + 2])
            {
                mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->pos[k], draw, 0xFF0000);
                draw++;
            }
        }
        k += 2;
    }
}

void    ft_draw(t_struct *all)
{
    int    k;
    int    draw;

    k = 0;
    while (k < all->size)
    {
        if (all->pos[k + 1] == all->pos[k + 3])
        {
            draw = all->pos[k];
            while (draw < all->pos[k + 4])
            {
                mlx_pixel_put(all->mlx_ptr, all->win_ptr, draw, all->pos[k + 1], 0xFF0000);
                draw++;
            }
        }
        k += 2;
    }    
    draw_vert(all);
}