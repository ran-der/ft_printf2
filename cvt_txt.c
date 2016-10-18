#include "ft_printf.h"

char			*cvt_txt(t_conv c, va_list args)
{
	char	c;;
	char	*ret;

	if (c.type == s)
	{
		ret = va_arg(args, char*);
		return (ft_strdup(ret));
	}
	if ((ret = (char*)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	c = va_arg(args, char);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}