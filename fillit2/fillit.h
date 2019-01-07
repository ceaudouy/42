/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:22:46 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/07 16:34:39 by ceaudouy         ###   ########.fr       */
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
int		*ft_parsing(char * tab, size_t i, size_t j, size_t x);
size_t		ft_grid(char **tab);
int		ft_error_main(int fd);
void	ft_letter(char	**tab);
void	ft_free_main(char **tab);
void	ft_free_info(int *info);
void	ft_info(int **info);
char	**ft_free_leaks(char *buf, char **tab);
char	*ft_solve(char **tab, size_t g);
char	**ft_clear(char **tab, size_t g);
char	*ft_backtrack(char **tab, size_t g, size_t i, size_t start);
char	*ft_fail(char **tab, size_t i, size_t g);
char	*ft_clear_tetri(char *tab, int *info, int xmin, int ymin);

#endif
