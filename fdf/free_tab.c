/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:24:02 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/03/05 18:32:13 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_pos(t_struct *all)
{
	int		i;

	i = 0;
	while (i < all->y)
		free(all->pos[i++]);
	free(all->pos);
}

void	free_tab(t_struct *all)
{
	int		i;

	i = 0;
	while (i < all->y)
	{
		free(all->pos[i]);
		free(all->alt[i]);
		free(all->map[i++]);
	}
	free(all->map);
	free(all->alt);
	free(all->pos);
	free(all->size);
}
