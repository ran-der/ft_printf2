#include "ft_printf.h"

static char		*get_prefix(t_conv c, uintmax_t nbr)
{
	if ((c.type == O || c.type == o) && c.altern && !nbr)
		return ("00");
	if (!nbr)
		return ("0");
	if (c.altern && (c.type == x || c.type == X || c.type == p))
		return (c.type == X ? "0X" : "0x");
	return (NULL);
}

static char		*ft_itoabase_pf(t_conv c, uintmax_t n, int range, char *base)
{
	int			i;
	char		*nbr;
	char		*prefix;
	int			base_len;

	if ((nbr = (char*)malloc(sizeof(char) * (range + 1))) == NULL)
		return (NULL);
	if ((prefix = get_prefix(c, n)) != NULL)
	{
		i = -1;
		while (prefix[++i] != '\0')
		nbr[i] = prefix[i];
	}
	base_len = ft_strlen(base);
	i = range - 1;
	while (n != 0)
	{
		nbr[i--] = base[n % base_len];
		n = n / base_len;
	}
	nbr[range] = '\0';
	return (nbr);
}

static int		find_range(t_conv c, uintmax_t n, int base_len)
{
	int			range;

	range = 0;
	if (c.type == p || (c.altern && (c.type == x || c.type == X) && n) ||\
		(c.altern && (c.type == o || c.type == O) && !n))
		range = 2;
	else if (c.altern && (c.type == o || c.type == O) && n)
		range = 1;
	while (n != 0)
	{
		range++;
		n = n / base_len;
	}
	return (range);
}

static uintmax_t		get_nbr(t_mod m, t_type t, va_list args)
{
	t_val			nbr;

	if ((t == u || t == o || t == x || t == X) && !m)
		return ((uintmax_t)(nbr.uin = va_arg(args, unsigned)));
	if (t != p && m == h)
		return ((uintmax_t)(unsigned short)(nbr.hun = va_arg(args, unsigned int)));
	if (((t == u || t == o || t == x || t == X) && m == l ) ||\
			((t == U || t == O) && !m))
		return ((uintmax_t)(nbr.lun = va_arg(args, unsigned long)));
	if (m == ll || t == p)
		return ((uintmax_t)(nbr.llu = va_arg(args, unsigned long long)));
	if (t != p && m == hh)
		return ((uintmax_t)(unsigned char)(nbr.uch = va_arg(args, unsigned int)));
	if (t != p && m == j)
		return ((nbr.unm = va_arg(args, uintmax_t)));
	if (t != p && m == z)
		return ((uintmax_t)(nbr.uch = va_arg(args, size_t)));
	return (0);
}

char					*cvt_unbr(t_conv c, va_list args)
{
	uintmax_t		nbr;
	char			*res;
	int				range;
	char			*base;

	base = get_base(c.type);
	nbr = get_nbr(c.mod, c.type, args);
	range = find_range(c, nbr, ft_strlen(base));
	if ((res = ft_itoabase_pf(c, nbr, range, base)) == NULL)
		return (NULL);
	if (range < c.prec)
		if ((res = ft_chgprec(res, range, c.prec, get_pfxlen(res))) == NULL)
			return (NULL);
	return (res);
}
