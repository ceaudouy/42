/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:56:58 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/16 14:23:24 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(int n)
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

static void		ft_print(int n, char *tab, int neg, int len)
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

char			*ft_itoa(int n)
{
	int		neg;
	int		len;
	char	*tab;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	len = ft_len(n) + neg;
	if (!(tab = (char*)malloc(sizeof(*tab) * len + 2)))
		return (0);
	ft_print(n, tab, neg, len);
	return (tab);
}
