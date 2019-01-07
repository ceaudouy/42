/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:52:38 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/12 16:22:42 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*srce;
	unsigned char	stp;

	stp = (unsigned char)c;
	dest = (unsigned char*)dst;
	srce = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dest[i] = srce[i];
		if (srce[i] == stp)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
