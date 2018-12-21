/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:22:46 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/21 13:57:16 by ceaudouy         ###   ########.fr       */
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
int		ft_check_end(char *tab);
int		ft_grid(char **tab);
void	ft_letter(char	**tab);
char	*ft_solve(char **tab, int g);
char	*ft_clear(char *fgrid, int g);
char	*ft_backtrack(char *fgrid, char **tab, int i, int start, int g);
char	*ft_fail(char **tab, char *fgrid, int i, int g);

#endif
