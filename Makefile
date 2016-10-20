#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/03 18:53:21 by rvan-der          #+#    #+#              #
#    Updated: 2016/10/20 19:15:33 by rvan-der         ###   ########.fr        #
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
		cvt_snbr.c \
		cvt_unbr.c \

OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(CFLAG) $(SRC)
	ar rc $(NAME) libft/libft.a $(OBJ)
	ranlib $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
