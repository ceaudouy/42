/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:08:03 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/30 13:08:05 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int         *ft_flags(t_struct *all, size_t i)
{
	if (all->format[i + 1] >= '1' && all->format[i + 1] <= '9')
		all->option[6] = 1;
    while (all->format[i] && (!(all->format[i] >= 'a' && all->format[i] <= 'z')))
	{
		if (all->format[i] == '-')
			all->option[0] = 1;
		else if (all->format[i] == '+')
			all->option[1] = 1;
		else if (all->format[i] == ' ')
			all->option[2] = 1;
		else if ((all->format[i] == '0') && 
				(!(all->format[i - 1] >= '0' && all->format[i - 1] <= '9')))
			all->option[3] = 1;
		else if (all->format[i] == '#')
			all->option[4] = 1;
		else if (all->option[4] == 1 && all->format[i] >= '1' &&
				 all->format[i] <= '9')
			all->option[6] = 1;
        else if (all->format[i] == '.')
            all->option[5] = 1;
		i++;
	}
	if (all->option[0] == 0 && all->option[1] == 0 && all->option[2] == 0 && all->option[3] == 0
			&& all->option[4] == 0 && all->option[5] == 0 && all->option[6 == 0])
		all->option[7] = 1;
    return (all->option);
}

int			ft_option(t_struct *all, size_t i)
{
    all->option = ft_flags(all, i);
	/*printf("option[0] == %d\n", all->option[0]);
	printf("option[1] == %d\n", all->option[1]);
	printf("option[2] == %d\n", all->option[2]);
	printf("option[3] == %d\n", all->option[3]);
	printf("option[4] == %d\n", all->option[4]);
	printf("option[5] == %d\n", all->option[5]);
	printf("option[6] == %d\n", all->option[6]);
   	*/if (all->option[0] == 1)
        all->ret = ft_neg(all, i);
    else if (all->option[1] == 1)
        all->ret = ft_plus(all, i);
	else if (all->option[2] == 1)
		all->ret = ft_space(all, i); 
	else if (all->option[3] == 1)
		all->ret = ft_zero(all, i);
	else if (all->option[4] == 1)	
		all->ret = ft_diese(all, i);
	else if (all->option[6] == 1)
		all->ret += ft_noflag(all, i);  
    return (all->ret);
} 