/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:49:03 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/24 10:49:04 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex(va_list ap)
{
	unsigned int			i;
	int						cnt;
	unsigned int			nb;
	char const				*base;
	char					*res;

	cnt = 0;
	i = va_arg(ap, int);
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

char	*ft_hex_char(va_list ap)
{
	unsigned char		i;
	int					cnt;
	unsigned char		nb;
	char const			*base;
	char				*res;

	cnt = 0;
	i = va_arg(ap, int);
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

char	*ft_hex_short(va_list ap)
{
	unsigned short int		i;
	int						cnt;
	unsigned short int		nb;
	char const				*base;
	char					*res;

	cnt = 0;
	i = va_arg(ap, int);
	nb = i;
	while ((i / 16) > 0)
	{
		cnt++;
		i /= 16;
	}
	i = cnt;
	if (!(res = (char*)malloc(sizeof(*res) * cnt + 1)))
		return (NULL);
	base = "0123456789abcdef";
	while (cnt >= 0)
	{
		res[cnt--] = (base[(nb % 16)]);
		nb /= 16;
	}
	res[i + 1] = '\0';
	return (res);
}

char	*ft_hex_long(va_list ap)
{
	unsigned long		i;
	int					cnt;
	unsigned long		nb;
	char const			*base;
	char				*res;

	cnt = 0;
	i = va_arg(ap, long);
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

char	*ft_hex_longlong(va_list ap)
{
	unsigned long long		i;
	int						cnt;
	unsigned long long		nb;
	char const				*base;
	char					*res;

	cnt = 0;
	i = va_arg(ap, long long);
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
