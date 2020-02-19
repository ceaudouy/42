/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 11:32:39 by mascorpi          #+#    #+#             */
/*   Updated: 2019/01/24 10:49:30 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_pointer(va_list ap)
{
	unsigned long	adr;
	char const		*base;
	char			*res;
	int				i;

	adr = (unsigned long)va_arg(ap, void*);
	base = "0123456789abcdef";
	i = 10;
	if (!(res = (char*)malloc(sizeof(*res) * 12)))
		return (NULL);
	while ((adr / 16) > 0 || i >= 10)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	res[0] = '0';
	res[1] = 'x';
	res[11] = '\0';
	return (res);
}
