#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int			pf;
	int			ft;
	int			i = 5;
	char		c;
	char		*str;
	wchar_t		wch;
	wchar_t		*wstr;
	unsigned long long	llu = 9223372036854775808;

	write(1, "ft_printf:\n", 11);
	ft = ft_printf("%C", 0);
	printf("ret= %d\n", ft);
	write(1, "printf:\n", 8);
	pf = printf("%C", 0);
	printf("ret= %d\n", pf);
	return (0);
}
