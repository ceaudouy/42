/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:24:34 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/16 16:16:22 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*rtn;

	rtn = (char *)haystack;
	i = 0;
	if (needle[0] == '\0')
		return (rtn);
	while (rtn[i] && i < len)
	{
		j = 0;
		while (needle[j] == rtn[i] && i < len)
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return (&rtn[i - j]);
		}
		i = i - j + 1;
	}
	return (NULL);
}
