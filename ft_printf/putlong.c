/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlong.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:27:19 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/22 16:23:23 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlonglong_d(long long nb)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putlonglong_d(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putlong_d(long nb)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putlong_d(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putshort_d(short nb)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putshort_d(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putchar_d(char nb)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putchar_d(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
}
