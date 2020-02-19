/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:23:40 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/24 10:49:21 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_octal(va_list ap)
{
	unsigned int			i;
	int						cnt;
	unsigned int			nb;
	char const				*base;
	char					*res;

	cnt = 0;
	i = va_arg(ap, int);
	nb = i;
	while ((i / 8) > 0)
	{
		cnt++;
		i /= 8;
	}
	if (!(res = (char*)malloc(sizeof(*res) * cnt + 2)))
		return (NULL);
	base = "01234567";
	i = cnt;
	while (cnt >= 0)
	{
		res[cnt--] = (base[(nb % 8)]);
		nb /= 8;
	}
	res[i + 1] = '\0';
	return (res);
}

char	*ft_octal_char(va_list ap)
{
	unsigned char		i;
	int					cnt;
	unsigned char		nb;
	char const			*base;
	char				*res;

	cnt = 0;
	i = va_arg(ap, int);
	nb = i;
	while ((i / 8) > 0)
	{
		cnt++;
		i /= 8;
	}
	if (!(res = (char*)malloc(sizeof(*res) * cnt + 2)))
		return (NULL);
	base = "01234567";
	i = cnt;
	while (cnt >= 0)
	{
		res[cnt--] = (base[(nb % 8)]);
		nb /= 8;
	}
	res[i + 1] = '\0';
	return (res);
}

char	*ft_octal_short(va_list ap)
{
	unsigned short		i;
	int					cnt;
	unsigned short		nb;
	char const			*base;
	char				*res;

	cnt = 0;
	i = va_arg(ap, int);
	nb = i;
	while ((i / 8) > 0)
	{
		cnt++;
		i /= 8;
	}
	i = cnt;
	if (!(res = (char*)malloc(sizeof(*res) * cnt + 2)))
		return (NULL);
	base = "01234567";
	while (cnt >= 0)
	{
		res[cnt--] = (base[(nb % 8)]);
		nb /= 8;
	}
	res[i + 1] = '\0';
	return (res);
}

char	*ft_octal_long(va_list ap)
{
	unsigned long		i;
	int					cnt;
	unsigned long		nb;
	char const			*base;
	char				*res;

	cnt = 0;
	i = va_arg(ap, long);
	nb = i;
	while ((i / 8) > 0)
	{
		cnt++;
		i /= 8;
	}
	if (!(res = (char*)malloc(sizeof(*res) * cnt + 2)))
		return (NULL);
	base = "01234567";
	i = cnt;
	while (cnt >= 0)
	{
		res[cnt--] = (base[(nb % 8)]);
		nb /= 8;
	}
	res[i + 1] = '\0';
	return (res);
}

char	*ft_octal_longlong(va_list ap)
{
	unsigned long long		i;
	int						cnt;
	unsigned long long		nb;
	char const				*base;
	char					*res;

	cnt = 0;
	i = va_arg(ap, long long);
	nb = i;
	while ((i / 8) > 0)
	{
		cnt++;
		i /= 8;
	}
	if (!(res = (char*)malloc(sizeof(*res) * cnt + 2)))
		return (NULL);
	base = "01234567";
	i = cnt;
	while (cnt >= 0)
	{
		res[cnt--] = (base[(nb % 8)]);
		nb /= 8;
	}
	res[i + 1] = '\0';
	return (res);
}
