/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:42:00 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/17 11:51:13 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	i = 0;
	if (c1[i] == '\0' || c2[i] == '\0')
		return (c1[i] - c2[i]);
	while (c1[i] && c2[i])
	{
		if (c1[i] == c2[i])
			i++;
		else
			return (c1[i] - c2[i]);
	}
	return (c1[i] - c2[i]);
}
