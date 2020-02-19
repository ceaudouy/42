/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:12:29 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/04/25 11:33:38 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	expose(t_struct *all)
{
	if (all->fractol == 1)
		julia(all);
	else if (all->fractol == 2)
		mendel(all);
	else if (all->fractol == 3)
		mendel2(all);
	else if (all->fractol == 4)
		mendel3(all);
	else if (all->fractol == 5)
		star(all);
	else if (all->fractol == 6)
		burnship(all);
	else if (all->fractol == 7)
		donut(all);
	else if (all->fractol == 8)
		tumeur(all);
	else if (all->fractol == 9)
		tree(all);
	else
		all->fractol = 0;
}

void	check(t_struct *all)
{
	if (ft_strcmp(all->str, "Julia") == 0)
		all->fractol = 1;
	else if (ft_strcmp(all->str, "Mendelbrot") == 0)
		all->fractol = 2;
	else if (ft_strcmp(all->str, "Mendel2") == 0)
		all->fractol = 3;
	else if (ft_strcmp(all->str, "Mendel3") == 0)
		all->fractol = 4;
	else if (ft_strcmp(all->str, "Star") == 0)
		all->fractol = 5;
	else if (ft_strcmp(all->str, "Burnship") == 0)
		all->fractol = 6;
	else if (ft_strcmp(all->str, "Donut") == 0)
		all->fractol = 7;
	else if (ft_strcmp(all->str, "Tumeur") == 0)
		all->fractol = 8;
	else if (ft_strcmp(all->str, "Tree") == 0)
		all->fractol = 9;
	else
		all->fractol = 0;
}
