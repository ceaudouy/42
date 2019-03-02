/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometrique.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 11:10:25 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/03/01 11:10:27 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void    isometrique(t_struct *all)
{
    int     i;
    int     j;
    int     k;
    int     x;
    int     y;

    i = 0;
    y = 40;
    if (!(all->pos = (int**)malloc(sizeof(*all->pos) * all->y)))
        return;
    while (i < all->y)
    {
        j = 0;
        k = 0;
        x = 1300;
        if (!(all->pos[i] = (int*)malloc(sizeof(*all->pos[i]) * all->size[i] * 2)))
            return ;
        while (j < all->size[i] * 2)
        {
            all->pos[i][j] = 0.5 * x - 0.5 * y;
            all->pos[i][j + 1] = (-all->alt[i][k] * 2) + 0.5 / 2 * x + 0.7 / 2 * y;
            j += 2;
            k++;
            x += (1000 / all->y) / 1.2;
        }
        i++;
        y += (1000 / all->y) / 1.2;
    }
}