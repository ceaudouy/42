/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:01:22 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/03/05 18:08:41 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham2(t_struct *all, int i, int k, float e)
{
	if (all->dx < 0)
	{
		if (all->dy > 0)
		{
			if (-all->dx >= all->dy)
				ft_octant4(all, e, k, i);
			else
				ft_octant3(all, e, k, i);
		}
		if (all->dy < 0 && all->dx < 0)
		{
			if (all->dx <= all->dy)
				ft_octant5(all, e, k, i);
			else
				ft_octant6(all, e, k, i);
		}
		if (all->dy == 0 && all->dx < 0)
			ft_octant_horleft(all, i, k);
	}
	if (all->dx == 0)
		if (all->dy > 0)
			ft_octant_vert(all, i, k);
	if (all->dy < 0 && all->dx == 0)
		ft_octant_vert2(all, i, k);
}
