/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:59:38 by mascorpi          #+#    #+#             */
/*   Updated: 2019/02/11 14:23:03 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_l_2(const char *c)
{
	c++;
	if (*c == 'o')
		return (12);
	if (*c == 'u')
		return (17);
	if (*c == 'x')
		return (22);
	if (*c == 'd' || *c == 'i')
		return (4);
	if (*c == 'X')
		return (27);
	return (-1);
}

void	ft_space_1(t_struct *all, int space)
{
	if (space == 0 && all->flag == 0 && all->str[0] != '-')
	{
		ft_putchar(' ');
		all->ret++;
	}
	while (space > 0)
	{
		ft_putchar(' ');
		space--;
		all->ret++;
	}
	if (all->str[0] == '\0' && all->flag == 2)
	{
		all->ret++;
		ft_putchar('\0');
	}
	ft_putstr(all->str);
	all->ret += ft_strlen(all->str);
}

void	ft_space_2(t_struct *all, int space)
{
	space--;
	all->ret++;
	ft_putstr(all->str);
	if (all->str[0] == '\0' && all->flag == 2)
	{
		all->ret++;
		ft_putchar('\0');
		space--;
	}
	all->ret += ft_strlen(all->str);
	while (space > 0)
	{
		ft_putchar(' ');
		space--;
		all->ret++;
	}
}

int		ft_zero_space(t_struct *all, int space)
{
	ft_putchar('+');
	all->ret++;
	space--;
	return (space);
}

int		ft_checkflag2(const char *c, size_t i)
{
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
	if (c[i] == 'j' && c[i + 1] == 'x')
		return (31);
	return (-1);
}
