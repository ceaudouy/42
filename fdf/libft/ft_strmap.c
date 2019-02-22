/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:10:30 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/13 16:13:02 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;
	char	tmp;

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
			new[i] = f(tmp);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (0);
}
