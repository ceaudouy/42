/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:11:46 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/21 11:11:49 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <fcntl.h>

typedef struct  s_struct
{
    void    *mlx_ptr;
    void    *win_ptr;
    char    **map;
    int     fd;
    int     x;
    int     y;
}               t_struct;
void    put_pixel(t_struct *all);
#endif