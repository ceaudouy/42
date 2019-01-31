/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:30:11 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/13 16:17:54 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	if (s1 && s2)
	{
		i = 0;
		j = 0;
		len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
		if (!(new = (char*)malloc(sizeof(*new) * len + 1)))
			return (NULL);
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
		while (s2[j])
			new[i++] = s2[j++];
		new[i] = '\0';
		return (new);
	}
	return (0);
}
