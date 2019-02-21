/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:23:46 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/11 14:55:43 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct				s_struct
{
	int						*option;
	int						flag;
	const char *restrict	format;
	char					*str;
	int						ret;
}							t_struct;
char						*(*g_func[32])(va_list);
void						ft_func(void);
int							ft_printf(const char *restrict format, ...);
char						*ft_decimal(va_list ap);
char						*ft_string(va_list ap);
char						*ft_char(va_list ap);
char						*ft_char_d(va_list ap);
char						*ft_long_d(va_list ap);
char						*ft_longlong_d(va_list ap);
void						ft_putlonglong_d(long long nb);
void						ft_putlong_d(long nb);
void						ft_putshort_d(short nb);
void						ft_putchar_d(char nb);
char						*ft_pointer(va_list ap);
char						*ft_short_d(va_list ap);
char						*ft_char_d(va_list ap);
int							*ft_flags(t_struct *all, size_t i);
char						*ft_octal(va_list ap);
char						*ft_octal_char(va_list ap);
char						*ft_octal_short(va_list ap);
char						*ft_octal_long(va_list ap);
char						*ft_octal_longlong(va_list ap);
char						*ft_unsigned(va_list ap);
char						*ft_unsignedshort(va_list ap);
char						*ft_unsignedchar(va_list ap);
char						*ft_unsignedlong(va_list ap);
char						*ft_unsignedlonglong(va_list ap);
int							ft_hashtag(const char *restrict format, int *option,
								int i, char *str);
int							ft_sign(const char *restrict format, int *option,
								int i, char *str);
char						*ft_itoalonglong(long long n);
char						*ft_itoalong(long n);
char						*ft_itoa_ulong(unsigned long long n);
char						*ft_itoaunsigned(unsigned n);
char						*ft_hex(va_list ap);
char						*ft_hex_char(va_list ap);
char						*ft_hex_short(va_list ap);
char						*ft_hex_long(va_list ap);
char						*ft_hex_longlong(va_list ap);
char						*ft_hex_x(va_list ap);
char						*ft_hex_x_char(va_list ap);
char						*ft_hex_x_short(va_list ap);
char						*ft_hex_x_long(va_list ap);
char						*ft_hex_x_longlong(va_list ap);
int							ft_checkflag(const char *c, size_t i);
int							ft_checkflag_end(const char *c, int i);
int							ft_l(const char *c);
int							ft_h(const char *c);
char						*ft_float(va_list ap);
char						*ft_float_l(va_list ap);
char						*ft_float_long_d(va_list ap);
void						ft_neg(t_struct *all, size_t i, int space);
void						ft_plus(t_struct *all, size_t i, int space);
int							ft_option(va_list ap, t_struct *all, size_t i);
void						ft_noflag(t_struct *all, va_list ap);
void						ft_zero(t_struct *all, size_t i, int space);
void						ft_space(t_struct *all, size_t i, int space);
int							ft_diese(t_struct *all, size_t i);
void						ft_nbr(t_struct *all, size_t i);
int							ft_preci(va_list ap, t_struct *all, size_t i);
char						*ft_strchr(const char *s, int c);
char						*ft_hex_j(va_list ap);
int							ft_precifloat(va_list ap, t_struct *all,
								size_t prec);
void						ft_dieseoctal2(t_struct *all, size_t i, char c);
void						ft_diesehex_x2(t_struct *all, size_t i, char c);
void						ft_diesehex2(t_struct *all, size_t i, char c);
char						*ft_fill_zero_pre(long long tmp, char *deci,
								long double f, int pre);
char						*ft_fill_zero(long tmp, long double f);
void						ft_precistring_plus(t_struct *all, size_t i,
								size_t prec, size_t size);
void						ft_precistring_neg(t_struct *all, size_t i,
								size_t prec, size_t size);
char						*ft_approx(char *deci);
void						ft_nopreci_neg(t_struct *all, size_t i,
								size_t prec, int space);
void						ft_nopreci_1(t_struct *all, size_t i,
								int space, size_t prec);
void						ft_nopreci_2(t_struct *all, size_t prec);
void						ft_prechex_neg(t_struct *all, size_t i, size_t prec,
								size_t size);
void						ft_prechex_plus(t_struct *all, size_t i,
								size_t prec, size_t size);
void						ft_space_1(t_struct *all, int space);
void						ft_space_2(t_struct *all, int space);
int							ft_zero_space(t_struct *all, int space);
int							ft_l_2(const char *c);
int							ft_modulo(t_struct *all, int i, va_list ap);
int							ft_checkflag2(const char *c, size_t i);

#endif
