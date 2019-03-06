/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altitude.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:44:43 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/03/06 11:04:33 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	alt2(t_struct *all)
{
	if (!(all->alt = (int**)malloc(sizeof(*all->alt) * (all->y + 1))))
		exit(1);
	if (!(all->size = (int*)malloc(sizeof(*all->size) * all->y)))
		exit(1);
}

void	ft_alt(t_struct *all)
{
	int		i;
	size_t	j;
	int		k;

	i = 0;
	alt2(all);
	while (i < all->y)
	{
		j = 0;
		k = 0;
		if (!(all->alt[i] = (int*)malloc(sizeof(*all->alt[i])
						* ft_strlen(all->map[i]))))
			exit(1);
		while (j < ft_strlen(all->map[i]))
		{
			while (j < ft_strlen(all->map[i]) && all->map[i][j] == ' ')
				j++;
			if (all->map[i][j] == '\n')
				break ;
			all->alt[i][k++] = ft_atoi(&all->map[i][j++]);
			while (all->map[i][j] && all->map[i][j] != ' ')
				j++;
		}
		all->size[i++] = k;
	}
}
