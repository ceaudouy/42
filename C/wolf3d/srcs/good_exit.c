/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:09:58 by msiesse           #+#    #+#             */
/*   Updated: 2019/08/06 18:26:01 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** function to exit the program and free everything we can
*/

void	good_exit(t_env *e)
{
	mlx_destroy_image(e->m.mlx, e->tex[0].img);
	mlx_destroy_image(e->m.mlx, e->tex[1].img);
	mlx_destroy_image(e->m.mlx, e->tex[2].img);
	mlx_destroy_image(e->m.mlx, e->tex[3].img);
	mlx_destroy_image(e->m.mlx, e->tex[4].img);
	mlx_destroy_image(e->m.mlx, e->tex[5].img);
	mlx_destroy_image(e->m.mlx, e->tex[6].img);
	mlx_destroy_window(e->m.mlx, e->m.win);
	reinit_points(&e->points);
	exit(EXIT_SUCCESS);
}
