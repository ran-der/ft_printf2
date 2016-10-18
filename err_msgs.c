#include "ft_printf.h"

char		*conv_err(char c)
{
	write(2, "invalid conversion : \"%", 22);
	write(2, &c, 1);
	write(2, "\"\n", 1);
	return (NULL);
}