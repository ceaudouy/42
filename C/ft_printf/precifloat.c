/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precifloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:49:19 by mascorpi          #+#    #+#             */
/*   Updated: 2019/02/12 15:46:46 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_approx(char *deci)
{
	unsigned int		i;

	i = ft_strlen(deci);
	i--;
	if (deci[i] >= '5')
	{
		while (deci[i - 1] == '9')
		{
			deci[i - 1] = '0';
			i--;
		}
		deci[i - 1] = deci[i - 1] + 1;
	}
	i = ft_strlen(deci);
	i--;
	deci[i] = '\0';
	return (deci);
}

static char		*ft_float_pre(float f, size_t prec)
{
	long		tmp;
	char		*rtn;
	char		*deci;
	char		*temp;

	tmp = f;
	rtn = ft_itoalong(tmp);
	temp = rtn;
	rtn = ft_strjoin(rtn, ".");
	f = f - tmp;
	deci = ft_fill_zero_pre(tmp, deci, f, prec);
	free(temp);
	temp = rtn;
	if (f < 0)
		rtn = ft_strjoin(rtn, deci + 1);
	else
		rtn = ft_strjoin(rtn, deci);
	free(deci);
	free(temp);
	return (rtn);
}

static char		*ft_float_d_pre(double f, size_t prec)
{
	long		tmp;
	char		*rtn;
	char		*deci;
	char		*temp;

	tmp = f;
	rtn = ft_itoalong(tmp);
	temp = rtn;
	rtn = ft_strjoin(rtn, ".");
	f = f - tmp;
	deci = ft_fill_zero_pre(tmp, deci, f, prec);
	free(temp);
	temp = rtn;
	if (f < 0)
		rtn = ft_strjoin(rtn, deci + 1);
	else
		rtn = ft_strjoin(rtn, deci);
	free(deci);
	free(temp);
	return (rtn);
}

static char		*ft_float_long_d_pre(long double f, size_t prec)
{
	long		tmp;
	char		*rtn;
	char		*deci;
	char		*temp;

	tmp = f;
	rtn = ft_itoalong(tmp);
	temp = rtn;
	rtn = ft_strjoin(rtn, ".");
	f = f - tmp;
	deci = ft_fill_zero_pre(tmp, deci, f, prec);
	free(temp);
	temp = rtn;
	if (f < 0)
		rtn = ft_strjoin(rtn, deci + 1);
	else
		rtn = ft_strjoin(rtn, deci);
	free(deci);
	free(temp);
	return (rtn);
}

int				ft_precifloat(va_list ap, t_struct *all, size_t prec)
{
	char		*rtn;
	float		f;
	double		d;
	long double	ld;

	if (all->flag == 28)
	{
		f = va_arg(ap, double);
		rtn = ft_float_pre(f, prec);
	}
	if (all->flag == 29)
	{
		d = va_arg(ap, double);
		rtn = ft_float_d_pre(d, prec);
	}
	if (all->flag == 30)
	{
		ld = va_arg(ap, long double);
		rtn = ft_float_long_d_pre(ld, prec);
	}
	ft_putstr(rtn);
	all->ret += ft_strlen(rtn);
	free(rtn);
	return (all->ret);
}
