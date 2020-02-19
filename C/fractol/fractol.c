/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:13:11 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/04/25 11:41:27 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mendel22(t_struct *all)
{
	all->tmp = all->z_r;
	all->z_r = all->z_r * all->z_r * all->z_r - 3 * all->z_r * all->z_i
		* all->z_i + all->c_r;
	all->z_i = 3 * all->tmp * all->tmp * all->z_i - all->z_i * all->z_i
		* all->z_i + all->c_i;
}

void	mendel2(t_struct *all)
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
				mendel22(all);
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

void	mendel33(t_struct *all)
{
	all->tmp = all->z_r;
	all->z_r = pow(all->z_r, 5) - 10 * pow(all->z_r, 3) * all->z_i
		* all->z_i + 5 * all->z_r * pow(all->z_i, 4) + all->c_r;
	all->z_i = 5 * pow(all->tmp, 4) * all->z_i - 10 * pow(all->tmp, 2)
		* pow(all->z_i, 3) + pow(all->z_i, 5) + all->c_i;
}

void	mendel3(t_struct *all)
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
				mendel33(all);
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
