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
    int     **pos;
    int     **alt;
    int     x;
    int     y;
    int     k;
    int     *size;
    int     dx;
    int     dy;
    int     x1;
    int     x2;
    int     y1;
    int     y2;
    int     signe;
}               t_struct;
void    put_pixel(t_struct *all);
void    ft_pos(t_struct *all);
void    ft_draw(t_struct *all);
void    ft_alt(t_struct *all);
void    ft_bresenham(t_struct *all, int i, int j, int k);
void    ft_bresenham_vert(t_struct *all, int i, int j, int k);
void    isometrique(t_struct *all);
void    ft_octant4(t_struct *all, float e, int k, int i);
void    ft_octant3(t_struct *all, float e, int k, int i);
void    ft_octant6(t_struct *all, float e, int k, int i);
void    ft_octant5(t_struct *all, float e, int k, int i);
void    ft_octant_horleft(t_struct *all, int i, int k);
void    ft_octant_vert(t_struct *all, int i, int k);
void    ft_octant_vert2(t_struct *all, int i, int k);

#endif
