/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:27:41 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/11 14:16:21 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_modulo2(t_struct *all, size_t i)
{
	if (ft_strchr(&all->format[i + 2], '%') && all->flag == -1)
		all->str = "%\0";
	else if (all->format[i + 1] == '%')
	{
		while (all->format[i + 1] &&
				ft_checkflag_end(&all->format[i + 1], 0) == -1)
		{
			ft_putchar(all->format[i + 1]);
			i++;
			all->ret++;
		}
	}
	else
		return (-1);
	return (i);
}

int			ft_modulo(t_struct *all, int i, va_list ap)
{
	int		mod;

	mod = 0;
	if (all->format[i] == '%')
	{
		all->flag = ft_checkflag(&all->format[i + 1], 0);
		if (all->flag == -1 || all->format[i + 1] == '%')
		{
			if (all->format[i + 1] == '%')
				mod = 1;
			i = ft_modulo2(all, i);
			if (i == -1)
				return (-1);
		}
		else if (all->flag != -1 && (!(all->flag >= 28 && all->flag <= 30)))
			all->str = g_func[all->flag](ap);
		if (mod == 0)
			ft_option(ap, all, i);
		if (mod == 0 && all->flag > 1 && all->format[i + 1] != '%')
			free(all->str);
		while (mod == 0 && all->format[i] &&
				ft_checkflag_end(&all->format[i], 0) == -1)
			i++;
	}
	return (i);
}
