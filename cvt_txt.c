#include "ft_printf.h"

char			*cvt_txt(t_conv c, va_list args)
{
	char	ch;
	char	*ret;

	if (c.type == s)
	{
		ret = va_arg(args, char*);
		return (ft_strdup(ret));
	}
	if ((ret = (char*)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	ch = (char)va_arg(args, int);
	ret[0] = ch;
	ret[1] = '\0';
	return (ret);
}
