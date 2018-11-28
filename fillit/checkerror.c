/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:20:33 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/27 17:44:04 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_checkerror_ver(char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (tab[i][0] != '\0' && j == 4)
			return (1);
		else if (j == 4)
			j = -1;
		j++;
		i++;
	}
	return (0);	
}

static int		ft_checkerror_hor(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#' || tab[i][j] == '.')
				j++;
			else
				return (1);
		} 
		if (j != 4 && tab[i][0] != '\0')
			return (1);
		i++;
	}
	return (0);
}

static int		ft_checkd(char **tab)
{
	int		i;
	int		j;
	int		nb;
	int		block;

	i = 0;
	nb = 0;
	block = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				nb++;
			j++;
		}
		if (block == 4)
		{
			if (nb != 4)
				return (1);
			nb = 0;
			block = -1;
		}
		block++;
		i++;
	}
	return (0);
}

static int		ft_checkpos(char **tab)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;	
	while (tab[i])
	{
		
	}
	return (0);
}

int				ft_checkerror(char **tab)
{
	if (ft_checkerror_hor(tab) == 1 || ft_checkerror_ver(tab) == 1)
		return (1);
	if (ft_checkd(tab) == 1 || ft_checkpos(tab) == 1)
		return (1);
	return (0);
}
