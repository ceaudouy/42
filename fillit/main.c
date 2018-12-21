/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:17:59 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/21 14:15:47 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**ft_read(int fd, char **tab)
{
	int		i;
	char	*buf;
	int		ret;

	i = 0;
	if (!(buf = ft_strnew(21)))
		{
			i = 0;	
			free(buf);
			while (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
				i++;
			}
			free(tab);
			tab = NULL;
		return (NULL);
		}
	while (i < 26)
		tab[i++] = NULL;
	i = 0;
	while ((ret = read(fd, buf, 21) > 0))
	{
		if (!(tab[i] = ft_strdup(buf)))
		{
			i = 0;	
			free(buf);
			while (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
				i++;
			}
			free(tab);
			tab = NULL;
			return (NULL);
		}
		ft_bzero(buf, 21);
		if (ft_checkerror(tab[i]) == 1 || ft_check_tetri(tab[i]) == 1 || 
				i == 27)
		{

			i = 0;	
			free(buf);
			while (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
				i++;
			}
			free(tab);
			return (NULL);
		}
		i++;
	}
	tab[i] = 0;
	free(buf);
	if (ret < 0 || (ret == 0 && !tab[0]))

	{	
		i = 0;	
		free(buf);
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);

		return (NULL);
	}
	if (ft_check_end(tab[i - 1]) == 1)
	{	
		i = 0;	
		free(buf);
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		return (NULL);
	}
	return (tab);
}

static void		ft_exec(char **tab)
{
	int		g;
	char	*fgrid;

	g = ft_grid(tab);
	ft_letter(tab);
	fgrid = ft_solve(tab, g);
	ft_putstr(fgrid);
	free(fgrid);
}

int				main(int ac, char **av)
{
	int		fd;
	char	**tab;
	int		i;


	i = 0;
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit sample.fillit\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd > 0)
	{
		if (!(tab = (char**)malloc(sizeof(*tab) * 27)))
			return (0);
		if (!(tab = ft_read(fd, tab)))
		{
			ft_putstr("error\n");
			close(fd);
			return (0);
		}
		ft_exec(tab);
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
	else
		ft_putstr("error\n");
	close(fd);
	return (0);
}
