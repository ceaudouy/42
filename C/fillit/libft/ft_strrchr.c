/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:34:15 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/09 13:41:17 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*rtn;

	rtn = (char*)s;
	i = 0;
	while (rtn[i])
		i++;
	while (i >= 0)
	{
		if (rtn[i] == c)
			return (&rtn[i]);
		i--;
	}
	return (NULL);
}
