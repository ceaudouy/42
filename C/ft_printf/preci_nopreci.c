/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preci_nopreci.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:55:17 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/10 17:58:35 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_nopreci_2(t_struct *all, size_t prec)
{
	if (all->str[0] == '-')
		ft_putchar('-');
	else if (all->option[1] == 1)
	{
		ft_putchar('+');
		all->ret++;
	}
	if (all->str[0] == '-')
		prec++;
	if (ft_strlen(all->str) < prec)
	{
		prec = prec - ft_strlen(all->str);
		while (prec > 0)
		{
			ft_putchar('0');
			all->ret++;
			prec--;
		}
	}
	if (all->str[0] == '\0' && all->flag == 2)
	{
		all->ret++;
		ft_putchar('\0');
	}
}

void		ft_nopreci_1(t_struct *all, size_t i, int space, size_t prec)
{
	if (all->format[i + 1] == 0)
		i++;
	space = ft_atoi(&all->format[i + 1]);
	if (all->str[0] == 0 && prec != 0)
		space--;
	if ((size_t)space >= prec)
	{
		if (prec != 0)
			space = space - ft_strlen(all->str) - 1;
		if (all->option[3] == 1 && ft_strlen(all->str) > prec)
			space--;
		if (all->option[1] == 1)
			space--;
		while (space > 0)
		{
			ft_putchar(' ');
			all->ret++;
			space--;
		}
	}
}

static void	ft_nopreci_neg2(t_struct *all, int space)
{
	ft_putstr(all->str);
	while (space > 0)
	{
		ft_putchar(' ');
		all->ret++;
		space--;
	}
}

void		ft_nopreci_neg(t_struct *all, size_t i, size_t prec, int space)
{
	if (all->option[1] == 1)
	{
		ft_putchar('+');
		all->ret++;
		space--;
	}
	if (ft_strlen(all->str) < prec)
	{
		prec = prec - ft_strlen(all->str);
		while (prec > 0)
		{
			ft_putchar('0');
			all->ret++;
			prec--;
		}
	}
	space += ft_atoi(&all->format[i + 2]) - ft_strlen(all->str) - 1;
	if (all->str[0] == '\0' && all->flag == 2)
	{
		all->ret++;
		ft_putchar('\0');
	}
	ft_nopreci_neg2(all, space);
}
