/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:22:46 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/13 16:09:24 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

char	**ft_read(int fd, char **tab);
int		ft_checkerror(char *tab);
int		ft_check_tetri(char *tab);
void	ft_letter(char	**tab);
int		ft_grid(char **tab);
char	*ft_solve(char **tab, int g);
void	ft_clear(char *fgrid, int g);

#endif
