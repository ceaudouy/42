/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:17:56 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/04/25 14:45:53 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_event(int x, int y, t_struct *all)
{
	if (x > 0 && x < W_IMG && y > 0 && y < H_IMG && all->mouse == 1)
	{
		all->ci = (double)((y - H_IMG / 2) / all->zoom);
		all->cr = (double)((x - W_IMG / 2) / all->zoom);
		expose(all);
		mlx_clear_window(all->mlx_ptr, all->win_ptr);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
		string(all);
	}
	return (0);
}

void	mouse_key2(int x, int y, t_struct *all)
{
	all->x1 = (x / all->zoom + all->x1) - (x / (all->zoom / 1.3));
	all->y1 = (y / all->zoom + all->y1) - (y / (all->zoom / 1.3));
	all->zoom /= 1.3;
	expose(all);
	mlx_clear_window(all->mlx_ptr, all->win_ptr);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr,
			0, 0);
	string(all);
}

int		mouse_key(int key, int x, int y, t_struct *all)
{
	if (x > 0 && x < W_IMG && y > 0 && y < W_IMG)
	{
		if (key == 4)
		{
			all->x1 = (x / all->zoom + all->x1) - (x / (all->zoom * 1.3));
			all->y1 = (y / all->zoom + all->y1) - (y / (all->zoom * 1.3));
			all->zoom *= 1.3;
			expose(all);
			mlx_clear_window(all->mlx_ptr, all->win_ptr);
			mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr,
					0, 0);
			string(all);
		}
		if (key == 5)
		{
			mouse_key2(x, y, all);
		}
	}
	return (0);
}
