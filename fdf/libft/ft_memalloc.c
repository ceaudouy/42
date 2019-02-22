/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:06:58 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/16 17:53:24 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!(new = (char*)malloc(sizeof(*new) * size)))
		return (NULL);
	while (i < size)
	{
		new[i] = 0;
		i++;
	}
	new[i] = '\0';
	return (&new[0]);
}
