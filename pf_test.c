#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		ret;
	int		retft;
	char	*str = "les nouilles cuisent au jus de canne";
	long unsigned int		i = 922337203;
	char	c = 'P';

	write(1, "ft_printf output:\n", 18);
	retft = ft_printf("abcdef%.0sabc\n", str);
	printf("ret = %d\n", retft);
	write(1, "\nprintf output:\n", 16);
	ret = printf("abcdef%.0sabc\n", str);
	printf("ret = %d\n", ret);
	return (0);
}
