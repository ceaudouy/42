/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:17:59 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/10 17:00:09 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			**ft_read(int fd, char **tab)
{
	int		i;
	char	*buf;
	int		ret;

	i = 0;
	while (i < 28)
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
				i >= 27)
			return (ft_free_leaks(buf, tab));
		i++;
	}
	if (ret < 0 || (ret == 0 && !tab[1]) || (ft_check_end(tab[i - 1]) == 1))
		return (ft_free_leaks(buf, tab));
	free(buf);
	return (tab);
}

static int			ft_exec(char **tab)
{
	size_t		g;
	int			**info;
	int			i;
	char		*fgrid;

	g = ft_grid(tab);
	i = 1;
	if (!(info = (int **)malloc(sizeof(*info) * 28)))
		return (1);
	while (tab[i])
	{
		info[i] = ft_parsing(tab[i], 0, 0, 0);
		tab[i] = ft_clear_tetri(tab[i], info[i], 3, 3);
		free(info[i]);
		i++;
	}
	free(info);
	if (!(fgrid = ft_solve(tab, g)))
		ft_free_main(tab);
	ft_putstr(fgrid);
	return (0);
}

int					main(int ac, char **av)
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
		if (!(tab = (char**)malloc(sizeof(char*) * 28)))
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
