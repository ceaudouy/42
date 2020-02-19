/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:38:48 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/16 17:25:39 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	s;

	i = 0;
	j = 0;
	k = ft_strlen((char*)src);
	while (dst[i] && i < size)
		i++;
	s = i;
	while (j < k && i < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i > s)
	{
		if (k + s >= size)
			i--;
		dst[i] = '\0';
	}
	return (k + s);
}
