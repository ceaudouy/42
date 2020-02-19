/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoalong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:48:30 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/12 15:45:36 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len(long n)
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

static void		ft_print(long n, char *tab, int neg, int len)
{
	int		i;

	i = len;
	while (i >= 0)
	{
		tab[i] = (char)((n) % 10) + '0';
		n = n / 10;
		i--;
	}
	if (neg == 1)
		tab[0] = '-';
	tab[len + 1] = '\0';
}

char			*ft_itoalong(long n)
{
	int		neg;
	int		len;
	char	*tab;
	char	*tmp;

	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	len = ft_len(n) + neg;
	if (!(tab = (char*)malloc(sizeof(*tab) * len + 2)))
		return (0);
	tmp = tab;
	ft_print(n, tab, neg, len);
	return (tab);
}
