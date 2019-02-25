/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altitude.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:44:43 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/25 16:44:46 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_relief(t_struct *all)
{
    int     i;
    size_t  j;

    i = 0;
    while (i < all->y)
    {
        j = 0;
        while (j < ft_strlen(all->map[i]))
        {
            if (all->map[i][j] == 0)
                j++;
            else
            {
                if (all->map[i][j] > 0)
                    all->pos[i][j * 2] -= all->map[i][j];
                if (all->map[i][j] < 0)
                    all->pos[i][j * 2] += all->map[i][j];
            }
            j++; 
        }
        i++;
    }
}
