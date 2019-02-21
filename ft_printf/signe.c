/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:56:06 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/10 17:44:42 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_neg(t_struct *all, size_t i, int space)
{
	if (all->option[2] == 1)
		ft_space(all, i, space);
	else
	{
		if (all->option[6] == 1)
			space = ft_atoi(&all->format[i + 2]) - ft_strlen(all->str);
		ft_putstr(all->str);
		while (space > 0)
		{
			all->ret++;
			ft_putchar(' ');
			space--;
		}
		all->ret += ft_strlen(all->str);
	}
}

void		ft_plus(t_struct *all, size_t i, int space)
{
	if (all->option[3] == 1)
		ft_zero(all, i, space);
	else
	{
		if (all->option[6] == 1)
			space = ft_atoi(&all->format[i + 1]) - ft_strlen(all->str) - 1;
		if (all->str[0] == '-')
			space--;
		while (space > 0)
		{
			all->ret++;
			ft_putchar(' ');
			space--;
		}
		if (all->str[0] == '-')
			ft_putstr(all->str);
		else
		{
			if (all->str[0] != '+')
				ft_putchar('+');
			all->ret++;
			ft_putstr(all->str);
		}
		all->ret += ft_strlen(all->str);
	}
}

void		ft_noflag(t_struct *all, va_list ap)
{
	if (all->flag >= 28 && all->flag <= 30)
		all->str = g_func[all->flag](ap);
	ft_putstr(all->str);
	if (all->str[0] == '\0' && all->flag == 2)
	{
		all->ret++;
		ft_putchar('\0');
	}
	all->ret += ft_strlen(all->str);
}

void		ft_zero(t_struct *all, size_t i, int space)
{
	char	c;

	c = ' ';
	if (all->option[3] == 1)
		c = '0';
	if (all->option[6] == 1)
		space = ft_atoi(&all->format[i + 1]) - ft_strlen(all->str);
	if (space <= 0)
		space = ft_atoi(&all->format[i + 3]) - ft_strlen(all->str);
	if (all->option[1] == 1 && all->str[0] != '-')
		space = ft_zero_space(all, space);
	if (all->str[0] == '-')
		ft_putchar('-');
	while (space > 0)
	{
		ft_putchar('0');
		all->ret++;
		space--;
	}
	if (all->str[0] == '-')
		ft_putstr(&all->str[1]);
	else
		ft_putstr(all->str);
	all->ret += ft_strlen(all->str);
}

void		ft_space(t_struct *all, size_t i, int space)
{
	if (all->str[0] == '\0' && all->flag == 2)
		space--;
	if (all->option[6] == 1)
		space += ft_atoi(&all->format[i + 2]) - ft_strlen(all->str);
	if (all->option[0] == 0)
		ft_space_1(all, space);
	else
		ft_space_2(all, space);
}
