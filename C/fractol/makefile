# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 14:19:02 by ceaudouy          #+#    #+#              #
#    Updated: 2019/04/25 14:19:03 by ceaudouy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol 

CC = gcc

CFLAGS = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit -lm

SRC = mendelbrot.c julia.c mouse.c keyboard.c expose.c \
	  fractol.c fractol2.c fractol3.c string.c main.c

INCLUDES = fractol.h

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

.c.o:
	$(CC) -c $^ -o $@

make :
		make -C libft/ all

$(NAME) : make $(OBJ)
			$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJ)   -I $(INCLUDES)

clean :
		make -C libft/ clean

fclean : clean
		rm -f $(NAME)
		rm -f $(OBJ)
		make -C libft/ fclean

re : fclean all

.PHONY: all, clean, fclean, re

