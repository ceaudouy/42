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

void    ft_alt(t_struct *all)
{
    int     i;
    size_t  j;
    int     k;

    i = 0;
    if (!(all->alt = (int**)malloc(sizeof(*all->alt) * (all->y + 1))))
        return ;
    if (!(all->size = (int*)malloc(sizeof(*all->size) * all->y)))
        return ;
    while (i < all->y)
    {
        j = 0;
        k = 0;
        if (!(all->alt[i] = (int*)malloc(sizeof(*all->alt[i]) * ft_strlen(all->map[i]))))
            return ;
        while (j < ft_strlen(all->map[i]))
        {
            all->alt[i][k++] = ft_atoi(&all->map[i][j++]);
            while (all->map[i][j] && all->map[i][j] != ' ')
                j++;
            j++;
        }
        all->size[i] = k; 
        i++;
    }
}
