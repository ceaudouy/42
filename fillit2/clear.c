/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:13:37 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/13 16:39:16 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clear(char *fgrid, int g)
{
	int		i;
	int		j;
	int		tot;
	
//	g--;
	tot = ((g + 1) * g); 
	i = 0;
	j = 1;
	while (i < tot)
	{
		if ((j % (g + 1)) == 0)
			fgrid[i] = '\n';
		else
			fgrid[i] = '.';
		i++;
		j++;
	}
	fgrid[i] = '\0';
}