#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		ret;
	int		retft;
	char	*str = "yolo";
	int		i = -76543210;

	write(1, "ft_printf output:\n", 18);
	retft = ft_printf("bbb%010.3svvvv\n", str);
	printf("ret = %d\n", retft);
	write(1, "printf output:\n", 15);
	ret = printf("bbb%010.3svvvv\n", str);
	printf("ret = %d\n", ret);
	return (0);
}
