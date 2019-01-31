# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 14:20:35 by ceaudouy          #+#    #+#              #
#    Updated: 2019/01/28 12:26:28 by ceaudouy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = decimal.c octal.c print_addres.c flags.c option.c \
	  printf.c putlong.c float.c ft_itoalong.c ft_itoalonglong.c \
	  ft_itoaunsigned.c func.c hex.c hex_x.c unsigned.c  ft_itoa_ulong.c \
	  libft/ft_itoa.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_putnbr.c\
	  libft/ft_strlen.c libft/ft_strjoin.c libft/ft_strdup.c libft/ft_atoi.c

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
