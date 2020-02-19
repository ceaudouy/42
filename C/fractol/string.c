/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:38:30 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/04/25 14:04:06 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	string2(t_struct *all)
{
	char	*s;
	char	*z;

	s = ft_itoa((int)all->iteration);
	z = ft_itoa((int)all->zoom);
	mlx_string_put(all->mlx_ptr, all->win_ptr, 900, 10, 16777215,
			"Iterations :");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 1030, 10, 16777215, s);
	mlx_string_put(all->mlx_ptr, all->win_ptr, 900, 30, 16777215, "Zoom :");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 1030, 30, 16777215, z);
	free(s);
	free(z);
}

void	string3(t_struct *all)
{
	mlx_string_put(all->mlx_ptr, all->win_ptr, 20, 150, 16777215,
			"1 : Julia");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 20, 170, 16777215,
			"2 : Mendelbrot");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 20, 190, 16777215,
			"3 : Mendel2");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 20, 210, 16777215,
			"4 : Mendel3");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 20, 230, 16777215,
			"5 : Star");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 20, 250, 16777215,
			"6 : Burnship");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 20, 270, 16777215,
			"7 : Donut");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 20, 290, 16777215,
			"8 : Tumeur");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 20, 310, 16777215,
			"9 : Tree");
}

void	string(t_struct *all)
{
	if (all->hidden == 0)
	{
		mlx_string_put(all->mlx_ptr, all->win_ptr, 10, 10, 16777215,
				"TAB pour afficher les touches");
	}
	else
	{
		mlx_string_put(all->mlx_ptr, all->win_ptr, 10, 10, 16777215,
				"TAB pour chacher les touches");
		mlx_string_put(all->mlx_ptr, all->win_ptr, 10, 30, 16777215,
				"molette souris : Zoom/Dezoom");
		mlx_string_put(all->mlx_ptr, all->win_ptr, 10, 50, 16777215,
				"+ : Augmenter le nombre d'iterations");
		mlx_string_put(all->mlx_ptr, all->win_ptr, 10, 70, 16777215,
				"- : Diminuer le nombre d'iterations");
		mlx_string_put(all->mlx_ptr, all->win_ptr, 10, 90, 16777215,
				"sur Julia, Tumeur, Donut: ");
		mlx_string_put(all->mlx_ptr, all->win_ptr, 20, 110, 16777215,
				"Entrer : bloquer la souris");
		mlx_string_put(all->mlx_ptr, all->win_ptr, 10, 130, 16777215,
				"Pave numerique :");
		string3(all);
	}
	string2(all);
}
