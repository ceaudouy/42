/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:57:55 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/12 18:50:33 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*rtn;
	char	p;

	p = (char)c;
	rtn = (char*)s;
	i = 0;
	while (rtn[i])
	{
		if (rtn[i] == p)
			return (&rtn[i]);
		i++;
	}
	if (p == '\0')
		return (&rtn[i]);
	return (NULL);
}
