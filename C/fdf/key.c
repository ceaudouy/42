/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:23:42 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/03/05 18:54:05 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_para2(t_struct *all, int key)
{
	if (key == 18)
	{
		all->posx = 0;
		all->posy = 0;
		all->coef = 0;
		free_pos(all);
	}
	if (key == 126)
	{
		all->posy -= 10;
		free_pos(all);
	}
	if (key == 125)
	{
		all->posy += 10;
		free_pos(all);
	}
}

void	key_para(t_struct *all, int key)
{
	if (key == 116)
	{
		all->coef++;
		free_pos(all);
	}
	if (key == 121)
	{
		all->coef--;
		free_pos(all);
	}
	if (key == 123)
	{
		all->posx -= 10;
		free_pos(all);
	}
	if (key == 124)
	{
		all->posx += 10;
		free_pos(all);
	}
	key_para2(all, key);
}

void	key_iso2(t_struct *all, int key)
{
	if (key == 19)
	{
		all->posx = 0;
		all->posy = 0;
		all->coef = 0;
		free_pos(all);
	}
	if (key == 13)
	{
		all->posy -= 10;
		free_pos(all);
	}
	if (key == 1)
	{
		all->posy += 10;
		free_pos(all);
	}
}

void	key_iso(t_struct *all, int key)
{
	if (key == 15)
	{
		all->coef++;
		isometrique(all);
	}
	if (key == 3)
	{
		all->coef--;
		free_pos(all);
	}
	if (key == 0)
	{
		all->posx -= 10;
		free_pos(all);
	}
	if (key == 2)
	{
		all->posx += 10;
		free_pos(all);
	}
	key_iso2(all, key);
}
