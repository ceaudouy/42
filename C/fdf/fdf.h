/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:11:46 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/03/06 11:03:28 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <fcntl.h>
# define RED 16385289
# define BLU 4851194
# define WHI 16777215

typedef struct	s_struct
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	**map;
	int		fd;
	int		**pos;
	int		**alt;
	int		y;
	int		*size;
	int		dx;
	int		dy;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		coef;
	int		posx;
	int		posy;
}				t_struct;
void			put_pixel(t_struct *all);
void			ft_pos(t_struct *all);
void			ft_draw(t_struct *all);
void			ft_alt(t_struct *all);
void			ft_bresenham(t_struct *all, int i, int k);
void			ft_bresenham_vert(t_struct *all, int i, int j, int k);
void			isometrique(t_struct *all);
void			ft_octant4(t_struct *all, float e, int k, int i);
void			ft_octant3(t_struct *all, float e, int k, int i);
void			ft_octant6(t_struct *all, float e, int k, int i);
void			ft_octant5(t_struct *all, float e, int k, int i);
void			ft_octant_horleft(t_struct *all, int i, int k);
void			ft_octant_vert(t_struct *all, int i, int k);
void			ft_octant_vert2(t_struct *all, int i, int k);
void			free_pos(t_struct *all);
void			free_tab(t_struct *all);
int				check_error(char *str);
void			key_para(t_struct *all, int key);
void			key_iso(t_struct *all, int key);
void			ft_bresenham2(t_struct *all, int i, int k, float e);
void			ft_octant_horright(t_struct *all, int i, int k);

#endif
