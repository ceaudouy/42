/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:31:18 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/03 15:09:56 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_check_piece(char *fgrid, char *piece, int let, int size, size_t idx)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	//while (*piece != '#')
	//	piece++;
	while (*piece)
	{
		if (*piece == '.')
			x++;
		if (*piece == '\n')
		{
			y++;
			x = 0;
		}
		if (*piece == '#')
		{
			if (fgrid[x + (size + 1) * y] != '.')
				return (0);
			x++;
		}
		piece++;
	}
	return (1);
}

void	ft_place_piece(char *fgrid, char *piece, int let, int size, size_t idx)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;

//	while (*piece != '#')
	//	piece++;
	while (*piece)
	{
		if (*piece == '.')
			x++;
		if (*piece == '\n')
		{
			y++;
			x = 0;
		}
		if (*piece == '#')
		{
			fgrid[x + (size + 1) * y] = let;
			x++;
		}
		piece++;
	}
			printf("%s\n", fgrid);
}

char	*ft_backtrack(char *fgrid, char **tab, int g, int i, size_t start)
{
	size_t		j;
	size_t		f;
	int			let;

	f = start;
	let = 'A' + i;
	while (tab[i])
	{
		j = 0;
		printf("%zu\n", i);
		if (ft_check_piece(fgrid, tab[i], let, g, start) == 1)
		{
			ft_place_piece(fgrid, tab[i], let, g, start);
			let++;
			i++;
			f = 0;
		}
		else
			f++;
		if (f >= ft_strlen(fgrid) - 1)
		{
			i--;
			j = 0;
			f = 0;
			start = 0;
			if (i == -1)
			{
				free(fgrid);
				return (ft_solve(tab, g + 1));
			}
			while (tab[i][j] == '.' || tab[i][j] == '\n')
				j++;
			while (fgrid[start] != tab[i][j] && fgrid[start])
				start++;
			start++;
			while (fgrid[f])
			{
				if (fgrid[f] == tab[i][j])
					fgrid[f] = '.';
				f++;
			}
			return (ft_backtrack(fgrid, tab, g, i, start));
		}
	}
	return (fgrid);
}

static int		*ft_parsing(char *tab, int i, int j, int x)
{
	int y;
	int	*info;
	
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
	i = 0;
	while (i < 8)
	{
//		printf("cordone = %d\n", info[i]);
		i++;
	}
//	info[i] = 0; -----------------------------------------------> no need car malloc set a 8
	return (info);
}

char	*ft_solve(char **tab, int g)
{
	int		tot;
	int		**info;
	int		i;
	int		t;
	char	*fgrid;

	i = 1;
	t = 0;
	tot = ((g + 1) * g);
	if (!(fgrid = (char *)malloc(sizeof(*fgrid) * (tot + 1))))
		return (NULL);
	if (!(info = (int **)malloc(sizeof(*info) * 28)))
		return (NULL);
	while (tab[t])
	{
		info[i] = ft_parsing(tab[t], 0, 0, 0);
		tab[t] = ft_clear_tetri(tab[t], info[i], 3, 3);
		i++;
		t++;
	}
//	info[0] = &g;
	info[i] = 0;
	fgrid = ft_clear(fgrid, g);
	fgrid = ft_backtrack(fgrid, tab, g, 0, 0);
	return (fgrid);
}
