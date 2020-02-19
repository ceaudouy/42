/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diese2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:29:05 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/10 14:49:30 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dieseoctal2(t_struct *all, size_t i, char c)
{
	int		space;

	space = ft_atoi(&all->format[i + 2]) - ft_strlen(all->str) - 1;
	while (space > 0)
	{
		ft_putchar(c);
		all->ret++;
		space--;
	}
	if (all->str[0] != '0')
	{
		ft_putchar('0');
		all->ret++;
	}
	ft_putstr(all->str);
}

void	ft_diesehex_x2(t_struct *all, size_t i, char c)
{
	int		space;

	if (all->str[0] != '0' && all->option[3] == 1)
	{
		ft_putchar('0');
		ft_putchar('X');
		all->ret += 2;
	}
	space = ft_atoi(&all->format[i + 2]) - ft_strlen(all->str) - 2;
	while (space > 0)
	{
		ft_putchar(c);
		all->ret++;
		space--;
	}
	if (all->str[0] != '0' && all->option[3] == 0)
	{
		ft_putchar('0');
		ft_putchar('X');
		all->ret += 2;
	}
	ft_putstr(all->str);
}

void	ft_diesehex2(t_struct *all, size_t i, char c)
{
	int		space;

	space = ft_atoi(&all->format[i + 2]) - ft_strlen(all->str) - 2;
	if (all->str[0] != '0' && all->option[3] == 1)
	{
		ft_putchar('0');
		ft_putchar('x');
		all->ret += 2;
	}
	while (space > 0)
	{
		ft_putchar(c);
		all->ret++;
		space--;
	}
	if (all->str[0] != '0' && all->option[3] == 0)
	{
		ft_putchar('0');
		ft_putchar('x');
		all->ret += 2;
	}
	ft_putstr(all->str);
}
