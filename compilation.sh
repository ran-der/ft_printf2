make -C libft/ fclean
make -C libft/
gcc -Wall -Wextra -Werror -c ft_printf.c ft_write_conv.c ft_get_conv.c pf_test.c cvt_snbr.c ft_printf.c cvt_txt.c flag_tests.c cvt_unbr.c ft_tools.c nbr_tools.c
gcc -L libft/ -lft ft_printf.o ft_write_conv.o ft_get_conv.o pf_test.o cvt_snbr.o ft_printf.o cvt_txt.o flag_tests.o cvt_unbr.o ft_tools.o nbr_tools.o
