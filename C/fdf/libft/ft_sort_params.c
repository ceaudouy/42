/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:56:53 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/20 11:04:16 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_sort_params(int ac, char **av)
{
	int		i;
	int		j;

	(void)ac;
	i = 0;
	j = 1;
	while (av[i])
	{
		j = 0;
		while (j < i)
		{
			if (ft_strcmp(av[j], av[j + 1]) > 0)
			{
				av[0] = av[j];
				av[j] = av[j + 1];
				av[j + 1] = av[0];
				j = 0;
			}
			j++;
		}
		i++;
	}
	ft_print_params(av);
}
