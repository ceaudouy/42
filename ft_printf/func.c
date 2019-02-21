/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:06:15 by mascorpi          #+#    #+#             */
/*   Updated: 2019/02/10 15:09:09 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_func2(void)
{
	g_func[18] = &ft_hex;
	g_func[19] = &ft_hex_char;
	g_func[20] = &ft_hex_short;
	g_func[21] = &ft_hex_long;
	g_func[22] = &ft_hex_longlong;
	g_func[23] = &ft_hex_x;
	g_func[24] = &ft_hex_x_char;
	g_func[25] = &ft_hex_x_short;
	g_func[26] = &ft_hex_x_long;
	g_func[27] = &ft_hex_x_longlong;
	g_func[28] = &ft_float;
	g_func[29] = &ft_float_l;
	g_func[30] = &ft_float_long_d;
	g_func[31] = &ft_hex_j;
}

void		ft_func(void)
{
	g_func[0] = &ft_decimal;
	g_func[1] = &ft_string;
	g_func[2] = &ft_char;
	g_func[3] = &ft_long_d;
	g_func[4] = &ft_longlong_d;
	g_func[5] = &ft_pointer;
	g_func[6] = &ft_short_d;
	g_func[7] = &ft_char_d;
	g_func[8] = &ft_octal;
	g_func[9] = &ft_octal_char;
	g_func[10] = &ft_octal_short;
	g_func[11] = &ft_octal_long;
	g_func[12] = &ft_octal_longlong;
	g_func[13] = &ft_unsigned;
	g_func[14] = &ft_unsignedshort;
	g_func[15] = &ft_unsignedchar;
	g_func[16] = &ft_unsignedlong;
	g_func[17] = &ft_unsignedlonglong;
	ft_func2();
}

int			ft_checkflag_end(const char *c, int i)
{
	if (c[i] == 'd' || c[i] == 'i')
		return (0);
	if (c[i] == 's')
		return (1);
	if (c[i] == 'c')
		return (2);
	if (*c == 'h' || *c == 'l' || *c == '+' || *c == '-' || *c == 'L')
		return (-1);
	if (c[i] == 'o')
		return (8);
	if (c[i] == 'p')
		return (5);
	if (c[i] == 'u')
		return (13);
	if (c[i] == 'x')
		return (18);
	if (c[i] == 'X')
		return (23);
	if (c[i] == 'f')
		return (28);
	return (-1);
}
