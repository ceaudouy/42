/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:17:59 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/27 17:43:57 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_read(int fd, char **tab)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line))
	{
		tab[i] = ft_strdup(line);
		free(line);
		i++;
	}
	tab[i] = 0;
	if (ft_checkerror(tab) == 1)
	   return (NULL);	
	return (tab);	
}

int		main(int ac, char **av)
{
	int		fd;
	char	**tab;

	if (ac != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (!(tab = (char**)malloc(sizeof(*tab) * 27)))
		return (0);
	fd = open(av[1], O_RDONLY);
	if (!(tab = ft_read(fd, tab)))
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	return (0);
}
