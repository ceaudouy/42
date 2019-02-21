/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:08:03 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/10 16:24:00 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*ft_flags(t_struct *all, size_t i)
{
	while (all->format[i] && (!(all->format[i] >= 'a' &&
					all->format[i] <= 'z')))
	{
		if (all->format[i] == '-')
			all->option[0] = 1;
		else if (all->format[i] == '+')
			all->option[1] = 1;
		else if (all->format[i] == ' ')
			all->option[2] = 1;
		else if ((all->format[i] == '0') &&
				(!(all->format[i - 1] >= '0' && all->format[i - 1] <= '9')))
			all->option[3] = 1;
		else if (all->format[i] == '#')
			all->option[4] = 1;
		else if (all->format[i] >= '1' && all->format[i] <= '9')
			all->option[6] = 1;
		else if (all->format[i] == '.')
			all->option[5] = 1;
		i++;
	}
	if (all->option[0] == 0 && all->option[1] == 0 &&
		all->option[2] == 0 && all->option[3] == 0 &&
		all->option[4] == 0 && all->option[5] == 0 && all->option[6] == 0)
		all->option[7] = 1;
	return (all->option);
}

int		ft_option(va_list ap, t_struct *all, size_t i)
{
	int		j;

	j = 0;
	while (j <= 7)
		all->option[j++] = 0;
	all->option = ft_flags(all, i);
	if (all->option[4] == 1 && (!(all->flag >= 28 && all->flag <= 30)))
		ft_diese(all, i);
	else if (all->option[5] == 1)
		ft_preci(ap, all, i);
	else if (all->option[2] == 1)
		ft_space(all, i, 0);
	else if (all->option[3] == 1)
		ft_zero(all, i, 0);
	else if (all->option[0] == 1)
		ft_neg(all, i, 0);
	else if (all->option[1] == 1)
		ft_plus(all, i, 0);
	else if (all->option[7] == 1)
		ft_noflag(all, ap);
	else if (all->option[6] == 1)
		ft_nbr(all, i);
	return (all->ret);
}
