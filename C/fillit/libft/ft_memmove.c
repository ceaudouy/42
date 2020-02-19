/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:31:49 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/12 17:55:57 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst > src)
	{
		while (len > 0)
		{
			((unsigned char*)(dst))[len - 1] = ((unsigned char*)(src))[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char*)(dst))[i] = ((unsigned char*)(src))[i];
			i++;
		}
	}
	return (dst);
}
