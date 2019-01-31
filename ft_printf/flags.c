/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:32:01 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/24 10:57:30 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_string(va_list ap)
{
	char	*str;

	str = va_arg(ap, char*);
	return (str);
}

char		*ft_char(va_list ap)
{
	int		c;
	char	*str;

	if (!(str = (char*)malloc(sizeof(*str) * 2)))
		return (NULL);
	c = va_arg(ap, int);
	str[0] = c;
	str[1] = '\0';
	return (str);
}