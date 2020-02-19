# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 14:20:35 by ceaudouy          #+#    #+#              #
#    Updated: 2019/02/08 16:26:06 by mascorpi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = decimal.c diese.c diese2.c fill_zero_pre.c flag_nbr.c\
	  flags.c float.c ft_itoa_ulong.c ft_itoalong.c ft_itoalonglong.c\
	  ft_itoaunsigned.c func.c hex_j.c hex_x.c hex.c\
	  octal.c option.c preci_hex.c preci_nopreci.c preci.c\
	  precifloat.c precistring.c print_addres.c printf.c signe.c\
	  unsigned.c ft_l_2.c mod.c\
	  libft/ft_itoa.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_putnbr.c\
	  libft/ft_strlen.c libft/ft_strjoin.c libft/ft_strdup.c libft/ft_atoi.c \
	  libft/ft_strchr.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

.c.o:
	$(CC) -c $^ -o $@ -I $(CFLAGS)

$(NAME) : $(OBJ) 
	ar rcs $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
