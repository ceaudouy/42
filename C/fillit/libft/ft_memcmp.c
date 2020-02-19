/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:15:20 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/16 14:55:37 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*d;
	unsigned char	*c;

	c = (unsigned char*)s1;
	d = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (c[i] == d[i])
			i++;
		else
			return (c[i] - d[i]);
	}
	i--;
	return (c[i] - d[i]);
}
