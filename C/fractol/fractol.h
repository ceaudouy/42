/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:29:08 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/04/25 14:46:24 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <fcntl.h>
# define W_IMG 1100
# define H_IMG 1100
# define W_WDW 1100
# define H_WDW 1100

typedef	struct	s_struct
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			sline;
	int			end;
	int			x;
	int			y;
	double		x1;
	double		y1;
	double		i;
	double		iteration;
	double		zoom;
	double		image_x;
	double		image_y;
	double		cr;
	double		ci;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	double		movex;
	double		movey;
	int			mouse;
	int			fractol;
	char		*str;
	double		value;
	int			hidden;
	char		string;
}				t_struct;
void			mendel(t_struct *all);
void			julia(t_struct *all);
void			star(t_struct *all);
void			tumeur(t_struct *all);
void			donut(t_struct *all);
int				mouse_key(int key, int x, int y, t_struct *all);
int				mouse_event(int x, int y, t_struct *all);
int				keyboard_key(int key, t_struct *all);
void			expose(t_struct *all);
void			check(t_struct *all);
void			mendel2(t_struct *all);
void			mendel3(t_struct *all);
void			burnship(t_struct *all);
void			init(t_struct *all);
void			tree(t_struct *all);
void			string(t_struct *all);

#endif
