/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:31:18 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/09 17:08:01 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_piece(char *fgrid, char *piece, size_t size, size_t idx)
{
	size_t	x;
	size_t	y;
	size_t	i;

	i = 0;
	x = 0;
	y = 0;
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

static void	ft_place_piece(char **tab, size_t i, size_t size, size_t idx)
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

int			ft_backtrack(char **tab, size_t g, size_t i, size_t start)
{
	int		let;

	let = 'A' + i - 1;
	while (start < ft_strlen(tab[0]))
	{
		if (ft_check_piece(tab[0], tab[i], g, start) == 1)
		{
			ft_place_piece(tab, i, g, start);
			return (0);
		}
		else
			start++;
	}
	return (1);
}

int			*ft_parsing(char *tab, size_t i, size_t j, size_t x)
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

char		*ft_solve(char **tab, size_t g)
{
	size_t	i;
	size_t	start;

	i = 1;
	start = 0;
	if (!(tab[0] = (char *)malloc(sizeof(*tab) * (((g + 1) * g) + 1))))
		return (NULL);
	tab = ft_clear(tab, g);
	while (tab[i])
	{
		if (ft_backtrack(tab, g, i, start) == 0)
		{
			i++;
			start = 0;
		}
		else
		{
			i--;
			start = ft_fail(tab, i, g, 'A' + i - 1);
		}
		if (i == 0)
			break ;
	}
	return (tab[0]);
}
