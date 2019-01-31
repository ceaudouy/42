/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:20:38 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/24 10:49:46 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unsigned(va_list ap)
{
	unsigned int		i;

	i = va_arg(ap, unsigned);
	return (ft_itoaunsigned(i));
}

char	*ft_unsignedshort(va_list ap)
{
	unsigned short	i;

	i = va_arg(ap, unsigned);
	return (ft_itoaunsigned(i));
}

char	*ft_unsignedchar(va_list ap)
{
	unsigned char	i;

	i = va_arg(ap, unsigned);
	return (ft_itoaunsigned(i));
}

char	*ft_unsignedlong(va_list ap)
{
	unsigned long	i;

	i = va_arg(ap, unsigned long);
	return (ft_itoa_ulong(i));
}

char	*ft_unsignedlonglong(va_list ap)
{
	unsigned long long	i;

	i = va_arg(ap, unsigned long long);
	return (ft_itoa_ulong(i));
}
