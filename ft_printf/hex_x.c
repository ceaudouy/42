/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:24:47 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/10 15:25:26 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex_x(va_list ap)
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
	base = "0123456789ABCDEF";
	i = cnt;
	while (cnt >= 0)
	{
		res[cnt--] = (base[(nb % 16)]);
		nb /= 16;
	}
	res[i + 1] = '\0';
	return (res);
}

char	*ft_hex_x_char(va_list ap)
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
	base = "0123456789ABCDEF";
	i = cnt;
	while (cnt >= 0)
	{
		res[cnt--] = (base[(nb % 16)]);
		nb /= 16;
	}
	res[i + 1] = '\0';
	return (res);
}

char	*ft_hex_x_short(va_list ap)
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
	base = "0123456789ABCDEF";
	while (cnt >= 0)
	{
		res[cnt--] = (base[(nb % 16)]);
		nb /= 16;
	}
	res[i + 1] = '\0';
	return (res);
}

char	*ft_hex_x_long(va_list ap)
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
	base = "0123456789ABCDEF";
	i = cnt;
	while (cnt >= 0)
	{
		res[cnt--] = (base[(nb % 16)]);
		nb /= 16;
	}
	res[i + 1] = '\0';
	return (res);
}

char	*ft_hex_x_longlong(va_list ap)
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
	base = "0123456789ABCDEF";
	i = cnt;
	while (cnt >= 0)
	{
		res[cnt--] = (base[(nb % 16)]);
		nb /= 16;
	}
	res[i + 1] = '\0';
	return (res);
}
