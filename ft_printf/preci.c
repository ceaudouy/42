/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preci.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:02:59 by mascorpi          #+#    #+#             */
/*   Updated: 2019/02/10 16:27:01 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_precistring(t_struct *all, size_t i, size_t prec)
{
	size_t	j;
	size_t	size;

	j = 0;
	size = prec;
	if (prec > ft_strlen(all->str))
		size = ft_strlen(all->str);
	if (all->option[0] == 1)
		ft_precistring_plus(all, i, prec, size);
	else
		ft_precistring_neg(all, i, prec, size);
	return (all->ret);
}

int			ft_nopreci(t_struct *all, size_t i, int space, size_t prec)
{
	if (all->option[0] == 1)
		ft_nopreci_neg(all, i, prec, space);
	else
	{
		ft_nopreci_1(all, i, space, prec);
		ft_nopreci_2(all, prec);
		if (all->str[0] == '-')
			ft_putstr(&all->str[1]);
		else
			ft_putstr(all->str);
	}
	all->ret += ft_strlen(all->str);
	return (all->ret);
}

int			ft_prec_hex(t_struct *all, size_t i, size_t prec)
{
	size_t	zero;
	size_t	size;

	size = prec;
	if (prec < ft_strlen(all->str))
		size = ft_strlen(all->str);
	zero = prec - ft_strlen(all->str);
	if (all->option[0] == 1)
		ft_prechex_neg(all, i, prec, size);
	else
		ft_prechex_plus(all, i, prec, size);
	return (all->ret);
}

int			ft_preci(va_list ap, t_struct *all, size_t i)
{
	int		space;
	size_t	prec;
	size_t	j;

	j = i;
	space = 0;
	if ((!(all->flag >= 28 && all->flag <= 30)) && all->str[0] == '0')
		all->str[0] = '\0';
	while (all->format[j] != '.')
		j++;
	prec = ft_atoi(&all->format[j + 1]);
	if (all->flag == 1)
		all->ret = ft_precistring(all, i, prec);
	else if (all->flag >= 28 && all->flag <= 30)
		ft_precifloat(ap, all, prec);
	else if ((all->flag >= 18 && all->flag <= 27) ||
			(all->flag >= 8 && all->flag <= 12))
		ft_prec_hex(all, i, prec);
	else
		ft_nopreci(all, i, space, prec);
	return (all->ret);
}
