/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:17:59 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/30 11:31:17 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**ft_read(int fd, char **tab)
{
	int		i;
	char	*buf;
	int		ret;

	i = 0;
	while (i < 27)
		tab[i++] = 0;
	if (!(buf = ft_strnew(21)))
		return (ft_free_leaks(buf, tab));
	i = 1;
	while ((ret = read(fd, buf, 21) > 0))
	{
		if (!(tab[i] = ft_strdup(buf)))
			return (ft_free_leaks(buf, tab));
		ft_bzero(buf, 21);
		if (ft_checkerror(tab[i]) == 1 || ft_check_tetri(tab[i]) == 1 ||
				i == 27)
			return (ft_free_leaks(buf, tab));
		i++;
	}
	tab[i] = 0;
	if (ret < 0 || (ret == 0 && !tab[1]) || (ft_check_end(tab[i - 1]) == 1))
		return (ft_free_leaks(buf, tab));
	free(buf);
	return (tab);
}

static void		ft_exec(char **tab)
{
	size_t		g;
	char	*fgrid;

	g = ft_grid(tab);
	ft_letter(tab);
	fgrid = ft_solve(tab, g);
	ft_putstr(tab[0]);
	free(fgrid);
}

int				main(int ac, char **av)
{
	int		fd;
	char	**tab;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit sample.fillit\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd > 0)
	{
		if (!(tab = (char**)malloc(sizeof(*tab) * 28)))
		{
			close(fd);
			return (0);
		}
		if (!(tab = ft_read(fd, tab)))
			return (ft_error_main(fd));
		ft_exec(tab);
		ft_free_main(tab);
	}
	else
		ft_putstr("error\n");
	close(fd);
	return (0);
}
