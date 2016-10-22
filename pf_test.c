#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		ret;
	int		retft;
	int		i = 8192;
	//char	*str = "yolo";
	//char		c = 'z';

	write(1, "ft_printf output:\n", 18);
	retft = ft_printf("bbb%#xxxx\n", i);
	printf("ret = %d\n", retft);
	write(1, "printf output:\n", 15);
	ret = printf("xxx%#xxxx\n", i);
	printf("ret = %d\n", ret);
	return (0);
}