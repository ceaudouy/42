/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:32:33 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/29 12:20:26 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int		i;
	float	f;
	int		ret;
	int		ret2;

	i = 52;
	f = 42.123456789;
	ret = printf("lui %#20o\n", i);
	printf("%d\n", ret);	
	ret2 = ft_printf("moi %#20o\n", i);
	printf("%d\n", ret2);
	/*
	long double i = 891478.486 * 245.545;
	
	//printf("%5%", 42);
	ret = printf("lui = %-10d\n", -42);
	puts("*****");
	ret2 = ft_printf("moi = %-10d\n", -42);
	puts("*****");
	printf("%d\n", ret);	
	printf("%d\n", ret2);	
	*/return (0);
}