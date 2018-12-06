/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:17:59 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/06 17:41:06 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_read(int fd, char **tab)
{
	int		i;
	char	buf[17];
	char	*tmp;
	int		ret;

	i = 0;
	while ((ret = read(fd, buf, 16) > 0))
	{
		buf[16] = '\0';
		if (tab[i] == NULL)
			ft_strnew(1);
		tmp = tab[i];
		tab[i] = ft_strjoin(tab[i], buf);
		free(tmp);
		i++;
	}
	if (ret < 0)
		return (NULL);
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
