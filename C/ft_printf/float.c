/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:32:45 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/12 15:39:23 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_float(va_list ap)
{
	float	f;
	long	tmp;
	char	*rtn;
	char	*deci;
	char	*temp;

	f = va_arg(ap, double);
	tmp = f;
	rtn = ft_itoalong(tmp);
	temp = rtn;
	rtn = ft_strjoin(rtn, ".");
	f = f - tmp;
	deci = ft_fill_zero(tmp, f);
	free(temp);
	temp = rtn;
	if (f < 0)
		rtn = ft_strjoin(rtn, deci + 1);
	else
		rtn = ft_strjoin(rtn, deci);
	if (f != 0)
		free(deci);
	free(temp);
	return (rtn);
}

char		*ft_float_l(va_list ap)
{
	double	f;
	long	tmp;
	char	*rtn;
	char	*deci;
	char	*temp;

	f = va_arg(ap, double);
	tmp = f;
	rtn = ft_itoalong(tmp);
	temp = rtn;
	rtn = ft_strjoin(rtn, ".");
	f = f - tmp;
	deci = ft_fill_zero(tmp, f);
	free(temp);
	temp = rtn;
	if (f < 0)
		rtn = ft_strjoin(rtn, deci + 1);
	else
		rtn = ft_strjoin(rtn, deci);
	if (f != 0)
		free(deci);
	free(temp);
	return (rtn);
}

char		*ft_float_long_d(va_list ap)
{
	long double	f;
	long		tmp;
	char		*rtn;
	char		*deci;
	char		*temp;

	f = va_arg(ap, long double);
	tmp = f;
	rtn = ft_itoalong(tmp);
	temp = rtn;
	rtn = ft_strjoin(rtn, ".");
	f = f - tmp;
	deci = ft_fill_zero(tmp, f);
	free(temp);
	temp = rtn;
	if (f < 0)
		rtn = ft_strjoin(rtn, deci + 1);
	else
		rtn = ft_strjoin(rtn, deci);
	if (f != 0)
		free(deci);
	free(temp);
	return (rtn);
}
