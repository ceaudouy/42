/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:29:13 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/04/25 12:30:37 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exec(t_struct *all)
{
	all->mlx_ptr = mlx_init();
	all->win_ptr = mlx_new_window(all->mlx_ptr, W_WDW, H_WDW,
		"Fractol by CEAUDOUY");
	mlx_mouse_hook(all->win_ptr, mouse_key, all);
	mlx_key_hook(all->win_ptr, keyboard_key, all);
	mlx_hook(all->win_ptr, 6, 0, mouse_event, all);
	all->img_ptr = mlx_new_image(all->mlx_ptr, W_IMG, H_IMG);
	all->data = (int*)mlx_get_data_addr(all->img_ptr, &all->bpp,
			&all->sline, &all->end);
	expose(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	string(all);
	mlx_loop(all->mlx_ptr);
}

void	init(t_struct *all)
{
	all->mouse = 1;
	all->cr = 0.285;
	all->ci = 0.01;
	all->iteration = 20;
	all->zoom = 100;
	all->x1 = 0;
	all->y1 = 0;
	all->movex = -5;
	all->movey = -5;
	all->hidden = 0;
}

void	error_msg(void)
{
	ft_putstr("usage : ./fractol [fractal]\nfractals :\n");
	ft_putstr(" --> Mendelbrot\n --> Julia\n");
	ft_putstr(" --> Mendel2\n --> Mendel3\n");
	ft_putstr(" --> Star\n --> Burship\n");
	ft_putstr(" --> Donut\n --> Tumeur\n");
	ft_putstr(" --> Tree\n");
}

int		main(int ac, char **av)
{
	t_struct	*all;

	if (ac != 2)
	{
		error_msg();
		exit(0);
	}
	if (!(all = malloc(sizeof(t_struct) * 1)))
		return (0);
	all->str = av[1];
	check(all);
	if (all->fractol == 0)
	{
		error_msg();
		free(all);
		exit(0);
	}
	init(all);
	ft_exec(all);
}
