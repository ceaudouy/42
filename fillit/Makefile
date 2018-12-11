# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 11:06:56 by ceaudouy          #+#    #+#              #
#    Updated: 2018/12/11 11:50:39 by ceaudouy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = main.c checkerror.c letter.c 

INCLUDES = fillit.h

LIBFT = libft/libft.a

all : $(NAME)

.c.o :

$(NAME) :
	@make -C libft/ all
	@$(CC) -o $(NAME) $(CFLAGS) $(SRC) $(LIBFT) -I $(INCLUDES)
	@echo fillit

clean :
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo clean

fclean : clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo fclean

re : fclean all
