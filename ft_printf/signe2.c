/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signe2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:02:43 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/31 15:02:45 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_diesespace(t_struct *all, size_t i)
{
    int     space;

    space = ft_atoi(all->format[i + 2]) - ft_strlen(all->str);
    while (space > 0)
    {
        ft_putchar(' ');
        all->ret++;
        space--;        
    }    
}

int     ft_diese(t_struct *all, size_t i)
{
    if (all->flag >= 8 && all->flag <= 12)
    {
        if (all->option[6] == 1)
            ft_diesespace(all, i);
        ft_putchar('0');
        ft_putstr(all->str);
        all->ret += ft_strlen(all->str) + 1;
    }
    return (all->ret);    
}