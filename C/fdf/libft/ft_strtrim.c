/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:50:04 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/13 16:20:19 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	if (s)
	{
		j = 0;
		k = 0;
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j++;
		i = ft_strlen((char*)s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
		i++;
		if (i == 0)
			j = 0;
		if (!(new = (char*)malloc(sizeof(*new) * (i - j) + 1)))
			return (NULL);
		while (j < i)
			new[k++] = s[j++];
		new[k] = '\0';
		return (new);
	}
	return (0);
}
