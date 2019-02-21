/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:40:34 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/10 18:10:09 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>

size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strchr(const char *s, int c);
int					ft_atoi(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_itoa(int n);
void				ft_putnbr(int n);

#endif
