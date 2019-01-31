/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:56:06 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/30 13:56:54 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_neg(t_struct *all, size_t i)
{
    int     space;

    if (all->option[2] == 1)
        return (ft_space(all, i));
    space = ft_atoi(&all->format[i + 2]) - ft_strlen(all->str);
    ft_putstr(all->str);
    while (space > 0)
    {
        all->ret++;
        ft_putchar(' ');
        space--;
    }
   
    all->ret += ft_strlen(all->str);
    return (all->ret);
}

int     ft_plus(t_struct *all, size_t i)
{
    int     space;

    if (all->option[3] == 1)
        return (ft_zero(all, i));
    space = ft_atoi(&all->format[i + 1]) - ft_strlen(all->str) - 1;
    if (all->str[0] == '-')
    space++;
    while (space > 0)
    {
        all->ret++;
        ft_putchar(' ');
        space--;
    }
    if (all->str[0] == '-')
        ft_putstr(all->str);
    else
    {
        if (all->str[0] != '+')
            ft_putchar('+');
        all->ret++;
        ft_putstr(all->str);
    }
    all->ret += ft_strlen(all->str);
    return (all->ret);
}

int     ft_noflag(t_struct *all, size_t i)
{
    ft_putstr(all->str); 
    return (ft_strlen(all->str));
}

int     ft_zero(t_struct *all, size_t i)
{
    int     space;

    
    space = ft_atoi(&all->format[i + 1]) - ft_strlen(all->str);
    if (all->option[1] == 1)
    {
            ft_putchar('+');
            all->ret++;
            space--;
    }
    if (all->str[0] == '-')
        space++;
    while (space > 0)
    {
        ft_putchar('0');
        all->ret++;
        space--;
    }
    ft_putstr(all->str);
    all->ret += ft_strlen(all->str);
    return (all->ret);
}

int     ft_space(t_struct *all, size_t i)
{
    int     space;

    space = ft_atoi(&all->format[i + 2]) - ft_strlen(all->str);
    if (all->option[0] == 0)
    {
        while (space > 0)
        {
            ft_putchar(' ');
            space--;
            all->ret++;
        }
        ft_putstr(all->str);
        all->ret += ft_strlen(all->str);
    }
    else
    {
        ft_putchar(' ');
        space--;
        all->ret++;
        ft_putstr(all->str);
        all->ret += ft_strlen(all->str);
        while (space > 0)
        {
            ft_putchar(' ');
            space--;
            all->ret++;
        }
    }
    return (all->ret);
}