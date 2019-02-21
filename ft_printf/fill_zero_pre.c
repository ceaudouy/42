/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_zero_pre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:39:35 by mascorpi          #+#    #+#             */
/*   Updated: 2019/02/12 15:44:46 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_before(int i, int j, char *deci)
{
	char	*new;

	if (i > 7)
		return (ft_approx(deci));
	if (!(new = (char*)malloc(sizeof(char) * 8)))
		return (NULL);
	while (i >= 0)
	{
		new[j] = deci[i];
		i--;
		j--;
	}
	while (j >= 0)
	{
		new[j] = '0';
		j--;
	}
	free(deci);
	new = ft_approx(new);
	return (new);
}

static char	*ft_before_prec(int i, int j, char *deci)
{
	char	*new;

	if (i > j)
		return (ft_approx(deci));
	if (!(new = (char*)malloc(sizeof(char) * 8)))
		return (NULL);
	while (i >= 0)
	{
		new[j] = deci[i];
		i--;
		j--;
	}
	while (j >= 0)
	{
		new[j] = '0';
		j--;
	}
	free(deci);
	new = ft_approx(new);
	return (new);
}

char		*ft_fill_zero_pre(long long tmp, char *deci, long double f, int pre)
{
	int		i;
	int		j;

	pre = pre + 1;
	j = pre;
	while (pre > 0)
	{
		f *= 10;
		pre--;
	}
	tmp = f;
	deci = ft_itoalonglong(tmp);
	i = ft_strlen(deci);
	return (ft_before_prec(i, j, deci));
}

char		*ft_fill_zero(long tmp, long double f)
{
	int		i;
	int		j;
	char	*temp;
	char	*deci;

	j = 7;
	if (f == 0)
		deci = "000000\0";
	else
	{
		f = f * 10000000;
		tmp = f;
		deci = ft_itoalong(tmp);
		i = ft_strlen(deci);
		return (ft_before(i, j, deci));
	}
	return (deci);
}
