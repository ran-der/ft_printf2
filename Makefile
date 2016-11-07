#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/03 18:53:21 by rvan-der          #+#    #+#              #
#    Updated: 2016/11/06 23:59:21 by rvan-der         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
CC = gcc
CFLAG = -c -Wall -Werror -Wextra
SRC =	ft_get_conv.c \
		ft_write_conv.c \
		ft_printf.c \
		flag_tests.c \
		ft_tools.c \
		nbr_tools.c \
		cvt_txt.c \
		cvt_wtxt.c \
		cvt_snbr.c \
		cvt_unbr.c \

OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME):
	make -C libft re
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAG) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all
