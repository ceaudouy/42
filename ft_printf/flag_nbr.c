/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:00:27 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/10 15:03:19 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_nbr2(t_struct *all, size_t i, int space)
{
	if (all->option[6] == 1)
		space += ft_atoi(&all->format[i + 1]) - ft_strlen(all->str);
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
	ft_putstr(all->str);
}

void		ft_nbr(t_struct *all, size_t i)
{
	int		space;

	space = 0;
	if (all->str[0] == '\0' && all->flag == 2)
		space--;
	if (all->option[0] == 0)
		ft_nbr2(all, i, space);
	else
	{
		if (all->option[6] == 1)
			space += ft_atoi(&all->format[i + 2]) - ft_strlen(all->str);
		ft_putstr(all->str);
		if (all->str[0] == '\0' && all->flag == 2)
		{
			all->ret++;
			ft_putchar('\0');
		}
		while (space > 0)
		{
			ft_putchar(' ');
			all->ret++;
			space--;
		}
	}
	all->ret += ft_strlen(all->str);
}
