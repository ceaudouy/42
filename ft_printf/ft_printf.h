/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:23:46 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/29 16:09:56 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_struct
{
    int     *option;
    int     flag;
    const char *restrict     format;
    char    *str;
    int     ret;

}               t_struct;
char	*(*func[31])(va_list);
void    ft_func(void);
int		ft_printf(const char *restrict format, ...);
char	*ft_decimal(va_list ap);
char	*ft_string(va_list ap);
char	*ft_char(va_list ap);
char	*ft_char_d(va_list ap);
char	*ft_long_d(va_list ap);
char	*ft_longlong_d(va_list ap);
void	ft_putlonglong_d(long long nb);
void	ft_putlong_d(long nb);
void	ft_putshort_d(short nb);
void	ft_putchar_d(char nb);
char	*ft_pointer(va_list ap);
char	*ft_short_d(va_list ap);
char	*ft_char_d(va_list ap);
int		*ft_flags(t_struct *all, size_t i);
char	*ft_octal(va_list ap);
char	*ft_octal_char(va_list ap);
char	*ft_octal_short(va_list ap);
char	*ft_octal_long(va_list ap);
char	*ft_octal_longlong(va_list ap);
char	*ft_unsigned(va_list ap);
char	*ft_unsignedshort(va_list ap);
char	*ft_unsignedchar(va_list ap);
char	*ft_unsignedlong(va_list ap);
char	*ft_unsignedlonglong(va_list ap);
int		ft_hashtag(const char *restrict format, int *option, int i, char *str);
int		ft_sign(const char *restrict format, int *option, int i, char *str);
char	*ft_itoalonglong(long long n);
char	*ft_itoalong(long n);
char	*ft_itoa_ulong(unsigned long long n);
char	*ft_itoaunsigned(unsigned n);
char	*ft_hex(va_list ap);
char	*ft_hex_char(va_list ap);
char	*ft_hex_short(va_list ap);
char	*ft_hex_long(va_list ap);
char	*ft_hex_longlong(va_list ap);
char	*ft_hex_x(va_list ap);
char	*ft_hex_x_char(va_list ap);
char	*ft_hex_x_short(va_list ap);
char	*ft_hex_x_long(va_list ap);
char	*ft_hex_x_longlong(va_list ap);
int     ft_checkflag(const char *c, int i);
int     ft_checkflag_end(const char *c, int i);
int		ft_l(const char *c);
int		ft_h(const char *c);
char    *ft_float(va_list);
char    *ft_float_l(va_list);
char    *ft_float_long_d(va_list);
int     ft_neg(t_struct *all, size_t i);
int     ft_plus(t_struct *all, size_t i);
int     ft_option(t_struct *all, size_t i);
int     ft_noflag(t_struct *all, size_t i);
int     ft_zero(t_struct *all, size_t i);
int     ft_space(t_struct *all, size_t i);
int     ft_diese(t_struct *all, size_t i);

#endif
