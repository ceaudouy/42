/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:32:45 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/29 18:08:45 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_approx(char *deci)
{
	int		i;

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

static char	*ft_fill_zero(long tmp, char *deci, long double f)
{
	if (f == 0)
		deci = "000000\0";
	else
	{
		f = f * 10000000;
		tmp = f;
		deci = ft_itoalong(tmp);
		deci = ft_approx(deci);
	}
	return (deci);
}

char		*ft_float(va_list ap)
{
	float	f;
	long	tmp;
	char	*rtn;
	char	*deci;
	int		len;

	f = va_arg(ap, double);
	tmp = f;
	len = ft_strlen(ft_itoalong(tmp));
	if (!(rtn = (char*)malloc(sizeof(char) * (len + 7))))
		return (NULL);
	if (!(deci = (char*)malloc(sizeof(char) * 7)))
		return (NULL);
	rtn = ft_itoalong(tmp);
	rtn[len] = '.';
	f = f - tmp;
	deci = ft_fill_zero(tmp, deci, f);
	if (f < 0)
		rtn = ft_strjoin(rtn, deci + 1);
	else
		rtn = ft_strjoin(rtn, deci);
	return (rtn);
}

char		*ft_float_l(va_list ap)
{
	double	f;
	long	tmp;
	char	*rtn;
	char	*deci;
	int		len;

	f = va_arg(ap, double);
	tmp = f;
	len = ft_strlen(ft_itoalong(tmp));
	if (!(rtn = (char*)malloc(sizeof(char) * (len + 7))))
		return (NULL);
	if (!(deci = (char*)malloc(sizeof(char) * 7)))
		return (NULL);
	rtn = ft_itoalong(tmp);
	rtn[len] = '.';
	f = f - tmp;
	deci = ft_fill_zero(tmp, deci, f);
	if (f < 0)
		rtn = ft_strjoin(rtn, deci + 1);
	else
		rtn = ft_strjoin(rtn, deci);
	return (rtn);
}

char		*ft_float_long_d(va_list ap)
{
	long double	f;
	long		tmp;
	char		*rtn;
	char		*deci;
	int			len;

	f = va_arg(ap, long double);
	tmp = f;
	len = ft_strlen(ft_itoalong(tmp));
	if (!(rtn = (char*)malloc(sizeof(char) * (len + 7))))
		return (NULL);
	if (!(deci = (char*)malloc(sizeof(char) * 7)))
		return (NULL);
	rtn = ft_itoalong(tmp);
	rtn[len] = '.';
	f = f - tmp;
	deci = ft_fill_zero(tmp, deci, f);
	if (f < 0)
		rtn = ft_strjoin(rtn, deci + 1);
	else
		rtn = ft_strjoin(rtn, deci);
	return (rtn);
}
