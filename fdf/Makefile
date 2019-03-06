# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/06 10:09:00 by mascorpi          #+#    #+#              #
#    Updated: 2019/03/06 10:57:46 by mascorpi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf 

CC = gcc

CFLAGS = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit

SRC = altitude.c bresenham.c bresenham_vert.c draw.c free_tab.c key.c main.c \
		bresemham3.c bresenham4.c check_error.c isometrique.c put_pixel.c

INCLUDES = fdf.h

LIBFT = libft/libft.a

all : $(NAME)

make :
		make -C libft/ all

$(NAME) : make
			$(CC) -o $(NAME) $(CFLAGS) $(SRC) $(LIBFT) -I $(INCLUDES)

clean :
		make -C libft/ clean

fclean : clean
		rm -f $(NAME)
		make -C libft/ fclean

re : fclean all

.PHONY: all, clean, fclean, re
