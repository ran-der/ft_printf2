#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	write(1, "ft_printf output:\n", 18);
	ft_printf("hehehey\n");
	write(1, "printf output:\n", 15);
	printf("hehehey\n");
	return (0);
}
