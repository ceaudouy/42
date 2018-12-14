/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:32:11 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/11/24 15:32:13 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int end)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = (char*)malloc(sizeof(*new) * end + 1)))
		return (0);
	while (i < end)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
