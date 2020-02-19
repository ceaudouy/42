/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:36:19 by mascorpi          #+#    #+#             */
/*   Updated: 2018/12/12 16:40:13 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int	sqrt;
	int	tmp;

	sqrt = (nb / 2) + 1;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (sqrt * sqrt != nb && sqrt > 0)
	{
		tmp = sqrt * sqrt;
		if (tmp > nb && ((sqrt - 1) * (sqrt - 1)) < nb)
			return (sqrt);
		sqrt--;
	}
	if (sqrt == 0)
		return (0);
	else
		return (sqrt);
}
