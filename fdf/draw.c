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
     j = 0;
        k = 1;
        while (k < all->size[i] * 2)
        {
            if (i < all->y - 1 && all->pos[i][k - 1] == all->pos[i + 1][k - 1])
            {
                draw = all->pos[i][k];
                while (draw < all->pos[i + 1][k])
                {
                    if (all->alt[i][j] > 0)
                         mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->pos[i][k - 1], draw, 687460);
                    else if (all->alt[i][j] < 0)
                        mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->pos[i][k + 1], draw, 65280);
                    else
                        mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->pos[i][k - 1], draw, 0xFF0000);
                    draw++;
                }
            }
            j++;
            k += 2;
        }
        i++;
    }
}

void    ft_draw(t_struct *all)
{
    size_t    k;
    int    draw;
    int    i;
    int     j;

    i = 0;
    while (i < all->y)
    {
        k = 0;
        j = 0;
        while (k < all->size[i] * 2 - 2)
        {
            if (all->pos[i][k + 1] == all->pos[i][k + 3])
            {
                draw = all->pos[i][k];
                while (draw < all->pos[i][k + 2])
                {
                    if (all->alt[i][j] > 0)
                        mlx_pixel_put(all->mlx_ptr, all->win_ptr, draw, all->pos[i][k + 1], 687460);
                    else if (all->alt[i][j] < 0)
                        mlx_pixel_put(all->mlx_ptr, all->win_ptr, draw, all->pos[i][k + 1], 65280);
                    else
                        mlx_pixel_put(all->mlx_ptr, all->win_ptr, draw, all->pos[i][k + 1], 0xFF0000);
                    draw++;
                }
            }
            j++;
            k += 2;
        }
        i++;
    }    
    draw_vert(all);
}