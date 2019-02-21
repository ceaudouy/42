/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precistring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:41:48 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/10 17:03:43 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precistring_plus(t_struct *all, size_t i, size_t prec, size_t size)
{
	int		space;
	size_t	j;

	j = 0;
	space = ft_atoi(&all->format[i + 2]) - size;
	if (all->str[0] == '\0' && all->flag == 2)
	{
		all->ret++;
		ft_putchar('\0');
	}
	while (j < prec && j < ft_strlen(all->str))
	{
		ft_putchar(all->str[j++]);
		all->ret++;
	}
	while (space > 0)
	{
		ft_putchar(' ');
		all->ret++;
		space--;
	}
}

void	ft_precistring_neg(t_struct *all, size_t i, size_t prec, size_t size)
{
	int		space;
	size_t	j;

	j = 0;
	space = ft_atoi(&all->format[i + 1]) - size;
	while (space > 0)
	{
		ft_putchar(' ');
		all->ret++;
		space--;
	}
	if (all->str[0] == '\0' && all->flag == 2)
	{
		all->ret++;
		ft_putchar('\0');
	}
	while (j < prec && j < ft_strlen(all->str))
	{
		ft_putchar(all->str[j++]);
		all->ret++;
	}
}
