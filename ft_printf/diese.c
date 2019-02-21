/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signe2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:02:43 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/10 14:47:09 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_dieseoctal(t_struct *all, size_t i)
{
	int		space;
	char	c;

	c = ' ';
	if (all->option[3] == 1)
		c = '0';
	if (all->option[0] == 0)
		ft_dieseoctal2(all, i, c);
	else
	{
		space = ft_atoi(&all->format[i + 3]) - ft_strlen(all->str) - 1;
		if (all->str[0] != '0')
		{
			ft_putchar('0');
			all->ret++;
		}
		ft_putstr(all->str);
		while (space > 0)
		{
			ft_putchar(' ');
			all->ret++;
			space--;
		}
	}
}

static void	ft_diesehex_x(t_struct *all, size_t i)
{
	int		space;
	char	c;

	c = ' ';
	if (all->option[3] == 1)
		c = '0';
	if (all->option[0] == 0)
		ft_diesehex_x2(all, i, c);
	else
	{
		space = ft_atoi(&all->format[i + 3]) - ft_strlen(all->str) - 2;
		if (all->str[0] != '0')
		{
			ft_putchar('0');
			ft_putchar('X');
			all->ret += 2;
		}
		ft_putstr(all->str);
		while (space > 0)
		{
			ft_putchar(' ');
			all->ret++;
			space--;
		}
	}
}

static void	ft_diesehex(t_struct *all, size_t i)
{
	int		space;
	char	c;

	c = ' ';
	if (all->option[3] == 1)
		c = '0';
	if (all->option[0] == 0)
		ft_diesehex2(all, i, c);
	else
	{
		space = ft_atoi(&all->format[i + 3]) - ft_strlen(all->str) - 2;
		if (all->str[0] != '0')
		{
			ft_putchar('0');
			ft_putchar('x');
			all->ret += 2;
		}
		ft_putstr(all->str);
		while (space > 0)
		{
			ft_putchar(' ');
			all->ret++;
			space--;
		}
	}
}

int			ft_diese(t_struct *all, size_t i)
{
	if (all->option[5] == 1 && all->str[0] == '0'
			&& (all->flag < 8 || all->flag > 12))
		return (all->ret);
	if (all->flag >= 8 && all->flag <= 12)
		ft_dieseoctal(all, i);
	if (all->flag >= 18 && all->flag <= 22)
		ft_diesehex(all, i);
	if (all->flag >= 23 && all->flag <= 27)
		ft_diesehex_x(all, i);
	all->ret += ft_strlen(all->str);
	return (all->ret);
}
