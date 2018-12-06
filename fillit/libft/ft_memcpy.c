/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:17:22 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/12 18:52:09 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*c;
	unsigned char	*d;
	unsigned int	i;

	i = 0;
	c = (unsigned char*)dst;
	d = (unsigned char*)src;
	while (i < n)
	{
		c[i] = d[i];
		i++;
	}
	return (c);
}
