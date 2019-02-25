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
    int     size;
    int     x;
    int     y;

    i = 0;
    y = 150;
    all->size = 0;
    if (!(all->pos = malloc(sizeof(*all->pos) * all->y + 1)))
        return;
    while (i < all->y)
    {
        size = ft_strlen(all->map[i]);
        j = 0;
        x = 150;
        if (!(all->pos[i] = malloc(sizeof(*all->pos[i]) * (ft_strlen(all->map[i])) + 1)))
            return ;
        while (j < size - 1)
        {
            all->pos[i][j] = x;
            all->pos[i][j + 1] = y;
            j += 2;
            x += (1000 / all->y) / 2;
        }
        all->pos[i][j] = '\0';
        i++;
        y += (1000 / all->y) / 2;
    }
    all->pos[i] = 0;
    i = 0;
} 

void    put_pixel(t_struct *all)
{
    int     i;
    size_t     j;
    int     size;
    int     x;
    int     y;
    size_t     k;
    
    i = 0;
    while (i < all->y)
    {
        k = 0;
        while (k < ft_strlen(all->map[i]))
        {
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->pos[i][k], all->pos[i][k + 1], 0xFF0000);
            k += 2;
        }
        i++;
    }
  /*  while (i < all->y)
    {
        size = ft_strlen(all->map[i]);
        j = 0;
        while (j < size)
        {
            mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->pos[k], all->pos[k + 1], 0xFF0000);
            j += 2;
            k += 2;
        }
        i++;
    }*/
}