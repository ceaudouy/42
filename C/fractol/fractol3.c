/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:44:20 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/04/25 12:04:09 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burnship2(t_struct *all)
{
	all->tmp = all->z_r;
	all->z_r = fabs(all->z_r * all->z_r - all->z_i
			* all->z_i + all->c_r);
	all->z_i = fabs(2 * all->tmp * all->z_i) + all->c_i;
}

void	burnship(t_struct *all)
{
	all->y = 0;
	while (all->y < W_IMG)
	{
		all->x = -1;
		while (++all->x < H_IMG)
		{
			all->c_r = all->x / all->zoom + all->x1 + all->movex;
			all->c_i = all->y / all->zoom + all->y1 + all->movey;
			all->z_r = 0;
			all->z_i = 0;
			all->i = 0;
			while (((all->z_r * all->z_r + all->z_i * all->z_i) < 4)
					&& (all->i < all->iteration))
			{
				burnship2(all);
				all->i++;
			}
			if (all->i == all->iteration)
				all->data[(int)all->x + ((int)all->y) * W_IMG] = 0;
			else
				all->data[(int)all->x + ((int)all->y) * W_IMG] = all->i
					* 255 * 255 * 255 / all->iteration;
		}
		all->y++;
	}
}
