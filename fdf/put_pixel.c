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

void    put_pixel(t_struct *all)
{
    int     i;
    int     j;
    int     size;
    int     x;
    int     y;
    
    i = 0;
    y = 150;
    while (i < all->y)
    {
        size = ft_strlen(all->map[i]);
        j = 0;
        x = 150;
        while (j < size)
        {
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, 0xFF0000);
            x += (1500 / checksize(all)) / 2;
            j++;
        }
        i++;
        y += (1000 / all->y) / 2;
    }
}