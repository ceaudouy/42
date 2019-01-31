/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:06:15 by mascorpi          #+#    #+#             */
/*   Updated: 2019/01/29 16:08:44 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_func2(void)
{
	func[18] = &ft_hex;
	func[19] = &ft_hex_char;
	func[20] = &ft_hex_short;
	func[21] = &ft_hex_long;
	func[22] = &ft_hex_longlong;
	func[23] = &ft_hex_x;
	func[24] = &ft_hex_x_char;
	func[25] = &ft_hex_x_short;
	func[26] = &ft_hex_x_long;
	func[27] = &ft_hex_x_longlong;
	func[28] = &ft_float;
	func[29] = &ft_float_l;
	func[30] = &ft_float_long_d;
}

void        ft_func(void)
{
	func[0] = &ft_decimal;
	func[1] = &ft_string;
	func[2] = &ft_char;
	func[3] = &ft_long_d;
	func[4] = &ft_longlong_d;
	func[5] = &ft_pointer;
	func[6] = &ft_short_d;
	func[7] = &ft_char_d;
	func[8] = &ft_octal;
	func[9] = &ft_octal_char;
	func[10] = &ft_octal_short;
	func[11] = &ft_octal_long;
	func[12] = &ft_octal_longlong;
	func[13] = &ft_unsigned;
	func[14] = &ft_unsignedshort;
	func[15] = &ft_unsignedchar;
	func[16] = &ft_unsignedlong;
	func[17] = &ft_unsignedlonglong;
	ft_func2();
}

int		ft_checkflag_end(const char *c, int i)
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
