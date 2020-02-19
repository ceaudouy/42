/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:35:07 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/04/25 11:59:18 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	donut2(t_struct *all)
{
	all->tmp = all->z_r;
	all->z_r = fabs(pow(all->z_r, 5) - 10 * pow(all->z_r, 3) * all->z_i
			* all->z_i + 5 * all->z_r * pow(all->z_i, 4)) + all->c_r;
	all->z_i = fabs(5 * pow(all->tmp, 4) * all->z_i - 10 * pow(all->tmp, 2)
			* pow(all->z_i, 3) + pow(all->z_i, 5)) + all->c_i;
}

void	donut(t_struct *all)
{
	all->y = 0;
	while (all->y < 1100)
	{
		all->x = -1;
		while (++all->x < 1100)
		{
			all->c_r = -0.700000 + all->cr;
			all->c_i = -0.820000 + all->ci;
			all->z_r = all->x / all->zoom + all->x1 + all->movex;
			all->z_i = all->y / all->zoom + all->y1 + all->movey;
			all->i = 0;
			while ((all->z_r * all->z_r + all->z_i * all->z_i) < 4
					&& all->i < all->iteration)
			{
				donut2(all);
				all->i++;
			}
			if (all->i == all->iteration)
				all->data[(int)all->x + ((int)all->y) * W_IMG] = 0;
			else
				all->data[(int)all->x + ((int)all->y) * W_IMG] = all->i
					* 255 * 255 * 255 * 255 / all->iteration;
		}
		all->y++;
	}
}

void	tumeur2(t_struct *all)
{
	all->tmp = all->z_r;
	all->z_r = pow(all->z_r, 5) - 10 * pow(all->z_r, 3) * all->z_i
		* all->z_i + 5 * all->z_r * pow(all->z_i, 4) + all->c_r;
	all->z_i = sin(5 * pow(all->tmp, 4) * all->z_i - 10 * pow(all->tmp, 2)
			* pow(all->z_i, 3) + pow(all->z_i, 5)) + all->c_i;
}

void	tumeur(t_struct *all)
{
	all->y = 0;
	while (all->y < 1100)
	{
		all->x = -1;
		while (++all->x < 1100)
		{
			all->c_r = -1.417022285618 + all->cr;
			all->c_i = 0.0099534 + all->ci;
			all->z_r = all->x / all->zoom + all->x1 + all->movex;
			all->z_i = all->y / all->zoom + all->y1 + all->movey;
			all->i = 0;
			while ((all->z_r * all->z_r + all->z_i * all->z_i) < 4
					&& all->i < all->iteration)
			{
				tumeur2(all);
				all->i++;
			}
			if (all->i == all->iteration)
				all->data[(int)all->x + ((int)all->y) * W_IMG] = 0;
			else
				all->data[(int)all->x + ((int)all->y) * W_IMG] = all->i
					* 255 * 255 * 255 * 255 / all->iteration;
		}
		all->y++;
	}
}
