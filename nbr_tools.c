#include "ft_printf.h"

char		*get_base(t_type t)
{
	if (t == o || t == O)
		return ("01234567");
	if (t == x)
		return ("0123456789abcdef");
	if (t == X || t == p)
		return ("0123456789ABCDEF");
	return ("0123456789");
}

int				get_pfxlen(char *str)
{
	if (*str == ' ' || *str == '+' || *str == '-')
		return (1);
	if (*str == '0' && (str[1] == 'x' || str[1] == 'X'))
		return (2);
	return (0);
}

char			*min_nbr(void)
{
	char		*ret;

	if ((ret = (char*)malloc(sizeof(char) * 21)) == NULL)
		return (NULL);
	ret = ft_strcpy(ret, "−9223372036854775807");
	return (ret);
}

char			*ft_chgprec(char *res, int range, int prec, int pfx)
{
	char			*new;
	int				i;
	int				j;

	if ((new = (char*)malloc(sizeof(char) * prec + pfx + 1)) == NULL)
		return (NULL);
	i = 0;
	if (pfx)
	{
		while (i < pfx)
		new[i++] = *res;
	}
	while (i < prec - range - (pfx ? pfx : 0))
		new[i++] = '0';
	j = pfx;
	while (j < range + pfx)
		new[i++] = res[j++];
	new[i] = '\0';
	free(res);
	write(1, "chgprec\n", 8);
	return (new);
}
