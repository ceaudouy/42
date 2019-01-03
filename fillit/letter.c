/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:29:10 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/30 17:11:12 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_letter(char **tab)
{
	int	i;
	int j;
	int letter;

	i = 0;
	letter = 'A';
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				tab[i][j] = letter;
			j++;
		}
		i++;
		letter++;
	}
}
