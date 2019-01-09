# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 11:06:56 by ceaudouy          #+#    #+#              #
#    Updated: 2019/01/09 17:07:30 by ceaudouy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = main.c checkerror.c grid.c clear.c\
	  free.c solve.c 

INCLUDES = fillit.h

LIBFT = ../libft/libft.a

all : $(NAME)

make :
	@make -C ../libft/ all
	
$(NAME) : make 
	$(CC) -o $(NAME) $(CFLAGS) $(SRC) $(LIBFT) -I $(INCLUDES)

clean :
	@make -C ../libft/ clean

fclean : clean
	@rm -f $(NAME)
	@make -C ../libft/ fclean

re : fclean all
