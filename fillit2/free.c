/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 10:38:49 by mascorpi          #+#    #+#             */
/*   Updated: 2019/01/07 15:55:24 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_free_leaks(char *buf, char **tab)
{
	int	i;

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

void	ft_free_info(int *info)
{
//	int		i;

/*	i = 0;
i	while (i < 28)
	{
	//	if (info[i])
			free(info);
		//&info[i] = NULL;
		i++;
	}*/
	free(info);
	info = NULL;
}
void	ft_free_main(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

int		ft_error_main(int fd)
{
	ft_putstr("error\n");
	close(fd);
	return (0);
}
