/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:20:17 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/24 10:56:25 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_decimal(va_list ap)
{
	int		i;
	char	*str;
	char	*tmp;

	i = va_arg(ap, int);
	if (!(tmp = ft_itoa(i)))
		str = "0";
	str = tmp;
	free(tmp);
	return (str);
}

char		*ft_longlong_d(va_list ap)
{
	long long	nb;
	char		*str;

	nb = va_arg(ap, long long);
	str = ft_itoalonglong(nb);
	return (str);
}

char		*ft_long_d(va_list ap)
{
	long	nb;
	char	*str;

	nb = va_arg(ap, long);
	str = ft_itoalong(nb);
	return (str);
}

char		*ft_short_d(va_list ap)
{
	short	i;
	char	*str;

	i = va_arg(ap, int);
	str = ft_itoa(i);
	return (str);
}

char		*ft_char_d(va_list ap)
{
	char	i;
	char	*str;

	i = (char)va_arg(ap, int);
	str = ft_itoa(i);
	return (str);
}
