/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:48:00 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/12 16:05:57 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*rtn;

	rtn = (char *)haystack;
	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return (rtn);
	while (rtn[i])
	{
		j = 0;
		while (needle[j] == rtn[i])
		{
			j++;
			i++;
			if (needle[j] == '\0')
				return (&rtn[i - j]);
		}
		i = i - j + 1;
	}
	return (NULL);
}
