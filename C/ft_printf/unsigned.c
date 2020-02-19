/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:20:38 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/10 14:59:21 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unsigned(va_list ap)
{
	unsigned int	i;
	char			*str;

	i = va_arg(ap, unsigned);
	str = ft_itoaunsigned(i);
	return (str);
}

char	*ft_unsignedshort(va_list ap)
{
	unsigned short	i;
	char			*str;

	i = va_arg(ap, unsigned);
	str = ft_itoaunsigned(i);
	return (str);
}

char	*ft_unsignedchar(va_list ap)
{
	unsigned char	i;
	char			*str;

	i = va_arg(ap, unsigned);
	str = ft_itoaunsigned(i);
	return (str);
}

char	*ft_unsignedlong(va_list ap)
{
	unsigned long	i;
	char			*str;

	i = va_arg(ap, unsigned long);
	str = ft_itoa_ulong(i);
	return (str);
}

char	*ft_unsignedlonglong(va_list ap)
{
	unsigned long long	i;
	char				*str;

	i = va_arg(ap, unsigned long long);
	str = ft_itoa_ulong(i);
	return (str);
}
