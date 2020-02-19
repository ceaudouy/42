/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:16:50 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/10 17:13:32 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_l(const char *c)
{
	if (*c == 'o')
		return (11);
	if (*c == 'd' || *c == 'i')
		return (3);
	if (*c == 'u')
		return (16);
	if (*c == 'x')
		return (21);
	if (*c == 'X')
		return (26);
	if (*c == 'f')
		return (29);
	if (*c == 'l')
		return (ft_l_2(c));
	return (-1);
}

int			ft_h(const char *c)
{
	if (*c == 'd' || *c == 'i')
		return (6);
	if (*c == 'o')
		return (10);
	if (*c == 'u')
		return (14);
	if (*c == 'x')
		return (20);
	if (*c == 'X')
		return (25);
	if (*c == 'h')
	{
		c++;
		if (*c == 'd' || *c == 'i')
			return (7);
		if (*c == 'o')
			return (9);
		if (*c == 'u')
			return (15);
		if (*c == 'x')
			return (19);
		if (*c == 'X')
			return (24);
	}
	return (-1);
}

int			ft_checkflag(const char *c, size_t i)
{
	int		ret;

	while (i < ft_strlen(c))
	{
		if (c[i] == 'd' || c[i] == 'i')
			return (0);
		if (c[i] == 's')
			return (1);
		if (c[i] == 'c')
			return (2);
		if (c[i] == 'L')
			return (30);
		if (c[i] == 'l')
			return (ft_l(&c[i + 1]));
		if (c[i] == 'h')
			return (ft_h(&c[i + 1]));
		ret = ft_checkflag2(c, i);
		if (ret > -1)
			return (ret);
		i++;
	}
	return (-1);
}

int			ft_par(va_list ap, t_struct *all)
{
	int	i;

	i = 0;
	if (!(all->option = (int*)malloc(sizeof(int) * 8)))
		return (0);
	while (i < 8)
		all->option[i++] = 0;
	i = 0;
	while (all->format[i] && (size_t)i < ft_strlen(all->format))
	{
		if (all->format[i] == '%')
		{
			if (all->format[i] == '%')
				i = ft_modulo(all, i, ap);
			if (i == -1)
				return (all->ret);
		}
		else if (all->format[i] && ft_strlen(all->format) > (size_t)i)
		{
			all->ret++;
			ft_putchar(all->format[i]);
		}
		i++;
	}
	return (all->ret);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			cnt;
	t_struct	*all;

	if (!(all = malloc(sizeof(t_struct) * 1)))
		return (0);
	all->format = format;
	all->ret = 0;
	ft_func();
	va_start(ap, format);
	cnt = ft_par(ap, all);
	va_end(ap);
	free(all->option);
	free(all);
	return (cnt);
}
