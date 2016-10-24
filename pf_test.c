#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	char	*str = "yolo";
	int		i = -76543210;
	write(1, "ft_printf output:\n", 18);
	ft_printf("bbb%010.3svvvv\n", str);
	write(1, "printf output:\n", 15);
	printf("bbb%010.3svvvv\n", str);
	return (0);
}
