/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:17:59 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/10 17:40:20 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_read(int fd, char **tab)
{
	int		i;
	char	buf[22];
	char	*tmp;
	int		ret;

	i = 0;
	while ((ret = read(fd, buf, 21) > 0))
	{
		buf[21] = '\0';
		tab[i] = ft_strdup(buf);
		if (ft_checkerror(tab[i]) == 1 || ft_check_tetri(tab[i]) == 1)
			return (NULL);
		if (i == 27)
			return (NULL);
		i++;
	}
	if (ret < 0)
		return (NULL);
	tab[i] = 0;
	ft_letter(tab);
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
		close(fd);
		return (0);
	}
	close(fd);
	return (0);
}
