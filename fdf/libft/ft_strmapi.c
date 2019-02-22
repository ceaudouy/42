/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:57:45 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/13 16:11:41 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;
	char			tmp;

	if (s)
	{
		i = 0;
		while (s[i])
			i++;
		if (!(new = (char*)malloc(sizeof(*new) * i + 1)))
			return (0);
		i = 0;
		while (s[i])
		{
			tmp = s[i];
			new[i] = f(i, tmp);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (0);
}
