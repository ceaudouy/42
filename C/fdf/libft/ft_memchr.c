/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:04:21 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/12 17:57:34 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	d;

	d = (unsigned char)c;
	t = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (t[i] == d)
			return (&t[i]);
		i++;
	}
	return (NULL);
}
