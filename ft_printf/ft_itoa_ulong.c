/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ulong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:48:18 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/28 11:49:08 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len(unsigned long long n)
{
	int len;

	len = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void		ft_print(unsigned long long n, char *tab, int len)
{
	int		i;

	i = len;
	while (i >= 0)
	{
		tab[i] = (char)((n) % 10) + '0';
		n = n / 10;
		i--;
	}
	tab[len + 1] = '\0';
}

char			*ft_itoa_ulong(unsigned long long n)
{
	int		len;
	char	*tab;

	len = ft_len(n);
	if (!(tab = (char*)malloc(sizeof(*tab) * len + 2)))
		return (0);
	ft_print(n, tab, len);
	return (tab);
}
