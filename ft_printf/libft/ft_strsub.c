/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:01:29 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/13 16:21:28 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*new;

	if (s)
	{
		j = 0;
		if (!(new = (char*)malloc(sizeof(*new) * len + 1)))
			return (NULL);
		while (j < len)
		{
			new[j] = s[start];
			j++;
			start++;
		}
		new[j] = '\0';
		return (new);
	}
	return (0);
}
