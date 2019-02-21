/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_j.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 11:28:40 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/10 15:11:41 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex_j(va_list ap)
{
	unsigned long	i;
	int				cnt;
	unsigned long	nb;
	char const		*base;
	char			*res;

	cnt = 0;
	i = va_arg(ap, unsigned long);
	nb = i;
	while ((i / 16) > 0)
	{
		cnt++;
		i /= 16;
	}
	if (!(res = (char*)malloc(sizeof(*res) * cnt + 1)))
		return (NULL);
	base = "0123456789abcdef";
	i = cnt;
	while (cnt >= 0)
	{
		res[cnt--] = (base[(nb % 16)]);
		nb /= 16;
	}
	res[i + 1] = '\0';
	return (res);
}
