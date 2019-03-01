/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:21:55 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/22 10:21:56 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t     checksize(t_struct *all)
{
    int     i;
    size_t  size;

    i = 0;
    size = 0;
    while (i < all->y)
    {
        if (ft_strlen(all->map[i]) > size)
            size = ft_strlen(all->map[i]);
        i++;
    }
    return (size);
}

void       ft_pos(t_struct *all)
{
    int     i;
    int     j;
    int     k;
    int     x;
    int     y;

    i = 0;
    y = 150;
    if (!(all->pos = (int**)malloc(sizeof(*all->pos) * all->y)))
        return;
    while (i < all->y)
    {
        j = 0;
        k = 0;
        x = 150;
        if (!(all->pos[i] = (int*)malloc(sizeof(*all->pos[i]) * all->size[i] * 2)))
            return ;
        while (j < all->size[i] * 2)
        {
                all->pos[i][j] = x + 0.5 * all->alt[i][k];
                all->pos[i][j + 1] = y + (0.5 / 2) * all->alt[i][k];
            j += 2;
            k++;
            x += (1000 / all->y) / 2;
        }
        i++;
        y += (1000 / all->y) / 2;
    }
} 

void    put_pixel(t_struct *all)
{
    int     i;
    size_t  k;
    
    i = 0;
    while (i < all->y)
    {
        k = 0;
        while (k < all->size[i] * 2)
        {
                mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->pos[i][k], all->pos[i][k + 1], 16516059);
            k += 2;
        }
        i++;
    }
}