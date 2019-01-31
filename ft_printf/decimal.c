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
	int	i;

	i = va_arg(ap, int);
	return (ft_itoa(i));
}

char		*ft_longlong_d(va_list ap)
{
	long long nb;

	nb = va_arg(ap, long long);
	return (ft_itoalonglong(nb));
}

char		*ft_long_d(va_list ap)
{
	long	nb;
	char	*str;

	nb = va_arg(ap, long);
	return (ft_itoalong(nb));
}

char	*ft_short_d(va_list ap)
{
	short		i;

	i = va_arg(ap, int);
	return (ft_itoa(i));
}

char	*ft_char_d(va_list ap)
{
	char		i;

	i = (char)va_arg(ap, int);
	return (ft_itoa(i));
}