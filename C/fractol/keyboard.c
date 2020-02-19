/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:54:25 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/04/25 14:09:22 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		keyboard2(int key, t_struct *all)
{
	if (key == 123)
		all->movex += 0.1;
	if (key == 124)
		all->movex -= 0.1;
	if (key == 126)
		all->movey += 0.1;
	if (key == 125)
		all->movey -= 0.1;
	if (key == 48)
	{
		if (all->hidden == 0)
			all->hidden = 1;
		else
			all->hidden = 0;
	}
	return (0);
}

int		keyboard3(int key, t_struct *all)
{
	if (key == 83)
		all->fractol = 1;
	if (key == 84)
		all->fractol = 2;
	if (key == 85)
		all->fractol = 3;
	if (key == 86)
		all->fractol = 4;
	if (key == 87)
		all->fractol = 5;
	if (key == 88)
		all->fractol = 6;
	if (key == 89)
		all->fractol = 7;
	if (key == 91)
		all->fractol = 8;
	if (key == 92)
		all->fractol = 9;
	if (key >= 83 && key <= 92)
		init(all);
	return (0);
}

int		keyboard_key(int key, t_struct *all)
{
	if (key == 53)
	{
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		free(all);
		exit(1);
	}
	if (key == 69)
		all->iteration += 10;
	if (key == 78)
		all->iteration -= 10;
	if (key == 36)
	{
		if (all->mouse == 1)
			all->mouse = 0;
		else
			all->mouse = 1;
	}
	keyboard2(key, all);
	keyboard3(key, all);
	mlx_clear_window(all->mlx_ptr, all->win_ptr);
	expose(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	string(all);
	return (0);
}
