/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:31:18 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/07 17:04:14 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_check_piece(char *fgrid, char *piece, size_t size, size_t idx)
{
	size_t	x;
	size_t	y;
	size_t	i;
//	size_t	max;

//	max = 0;
	i = 0;
	x = 0;
	y = 0;
//	while (fgrid[max] != 0)
//		max++;
	while (piece[i])
	{
		if (piece[i] == '.')
			x++;
		if (piece[i] == '\n')
		{
			y++;
			x = 0;
		}
		if (piece[i] == '#')
		{
			if (fgrid[(x + (size + 1) * y) + idx] != '.')
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

void	ft_place_piece(char **tab, size_t i, size_t size, size_t idx)
{
	size_t	x;
	size_t	y;
	size_t	j;
	int		let;

	x = 0;
	y = 0;
	j = 0;
	let = 'A' + i - 1;
	while (tab[i][j])
	{
		if (tab[i][j] == '.')
			x++;
		if (tab[i][j] == '\n')
		{
			y++;
			x = 0;
		}
		if (tab[i][j] == '#')
		{
			tab[0][(x + (size + 1) * y) + idx] = let;
			x++;
		}
		j++;
	}
}

char	*ft_backtrack(char **tab, size_t g, size_t i, size_t start)
{
	size_t		f;
	int			let;

	f = start;
	let = 'A' + i - 1;
	while (tab[i])
	{
			if (ft_check_piece(tab[0], tab[i], g, f) == 1)
			{
				ft_place_piece(tab, i, g, f);
				let++;
				i++;
				f = 0;
			}
		else
			f++;
		if (ft_strlen(tab[0]) < f)
		{
			i--;
			return(ft_fail(tab, i, g));
		}
	}
	return (tab[0]);
}

int		*ft_parsing(char *tab, size_t i, size_t j, size_t x)
{
	size_t	y;
	int		*info;

	y = 0;
	if (!(info = (int *)malloc(sizeof(int) * 8)))
		return (NULL);
	while (tab[j])
	{
		if (tab[j] == '.')
			x++;
		else if (tab[j] == '\n')
		{
			y++;
			x = 0;
		}
		else if (tab[j] == '#')
		{
			info[i++] = x;
			info[i++] = y;
			x++;
		}
		j++;
	}
	return (info);
}

char	*ft_solve(char **tab, size_t g)
{
	int		tot;

	tot = ((g + 1) * g);
	if (!(tab[0] = (char *)malloc(sizeof(*tab) * (tot + 1))))
		return (NULL);
/*	if (!(info = (int **)malloc(sizeof(*info) * 28)))
		return (NULL);
	while (tab[i])
	{
		info[i] = ft_parsing(tab[i], 0, 0, 0);
		tab[i] = ft_clear_tetri(tab[i], info[i], 3, 3);
		free(info[i]);
		i++;
	}
	free(info);
*/	tab = ft_clear(tab, g);
//	printf("tab =%s\n", tab[0]);
//	printf("tab =%s\n", tab[1]);
	if (tab && g && tab[0])
		tab[0] = ft_backtrack(tab, g, 1, 0);
	return (tab[0]);
}
