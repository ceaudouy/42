/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:13:37 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/19 16:04:26 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_clear(char *fgrid, int g)
{
	int		i;
	int		j;
	int		tot;

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
	return (fgrid);
}
