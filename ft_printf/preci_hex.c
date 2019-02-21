/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preci_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:12:52 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/10 16:34:03 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_prechex2(t_struct *all, size_t prec, size_t space, size_t size)
{
	size_t	zero;

	zero = prec - ft_strlen(all->str);
	if (prec > ft_strlen(all->str))
	{
		while (zero > 0)
		{
			ft_putchar('0');
			all->ret++;
			zero--;
		}
	}
	ft_putstr(all->str);
	all->ret += ft_strlen(all->str);
	if (space > size)
	{
		while (space > 0)
		{
			ft_putchar(' ');
			all->ret++;
			space--;
		}
	}
}

void		ft_prechex_plus(t_struct *all, size_t i, size_t prec, size_t size)
{
	size_t	space;

	space = ft_atoi(&all->format[i + 1]);
	if (all->str[0] == '\0' && all->flag == 2)
	{
		all->ret++;
		ft_putchar('\0');
	}
	if (space > size)
	{
		space -= size;
		while (space > 0)
		{
			ft_putchar(' ');
			all->ret++;
			space--;
		}
	}
	ft_prechex2(all, prec, space, size);
}

static void	ft_prechex_neg2(t_struct *all, size_t space, size_t size)
{
	ft_putstr(all->str);
	all->ret += ft_strlen(all->str);
	if (space > size)
	{
		space -= size;
		while (space > 0)
		{
			ft_putchar(' ');
			all->ret++;
			space--;
		}
	}
}

void		ft_prechex_neg(t_struct *all, size_t i, size_t prec, size_t size)
{
	size_t	space;
	size_t	zero;

	zero = prec - ft_strlen(all->str);
	space = ft_atoi(&all->format[i + 2]);
	if (all->str[0] == '\0' && all->flag == 2)
	{
		all->ret++;
		ft_putchar('\0');
	}
	if (prec > ft_strlen(all->str))
	{
		while (zero > 0)
		{
			ft_putchar('0');
			all->ret++;
			zero--;
		}
	}
	ft_prechex_neg2(all, space, size);
}
