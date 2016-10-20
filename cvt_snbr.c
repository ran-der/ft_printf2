/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cvt_snbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016 10/05 18:31:54 by rvan-der          #+#    #+#             */
/*   Updated: 2016/10/20 19:23:16 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_prefix(t_conv c, intmax_t nbr)
{
	if (c.plus && !nbr)
		return ("+0");
	if (c.space && !nbr)
		return (" 0");
	if (!nbr)
		return ("0");
	if (c.plus && nbr >= 0)
		return ("+");
	if (nbr < 0)
		return ("-");
	if (c.space)
		return (" ");
	return (NULL);
}

static int		find_range(intmax_t n, t_conv c)
{
	int			range;

	range = ((n < 0 || c.plus || c.space) ? 1 : 0);
	range = (!n ? range + 1 : range);
	n = (n < 0 ? -n : n);
	while (n != 0)
	{
		range++;
		n = n / 10;
	}
	return (range);
}


static char		*ft_itoa_pf(t_conv c, intmax_t n, int range)
{
	int			i;
	char		*nbr;
	char		*prefix;

	if (n == -9223372036854775807)
		return (min_nbr());
	if ((nbr = (char*)malloc(sizeof(char) * (range + 1))) == NULL)
		return (NULL);
	if ((prefix = get_prefix(c, n)) != NULL)
	{
		i = -1;
		while (prefix[++i] != '\0')
		nbr[i] = prefix[i];
	}
	i = range - 1;
	n = (n < 0 ? -n : n);
	while (n != 0)
	{
		nbr[i--] = '0' + (n % 10);
		n = n / 10;
	}
	nbr[range] = '\0';
	return (nbr);
}


static intmax_t		get_nbr(t_mod m, t_type t, va_list args)
{
	t_val		nbr;

	if ((t == d || t == i) && !m) 
		return ((intmax_t)(nbr.din = va_arg(args, int)));
	if ((t == d || t == D || t == i) && m == h)
		return ((intmax_t)(short)(nbr.hin = va_arg(args, int)));
	if (((t == i || t == d || t == D) && m == l ) || (t == D && !m))
		return ((intmax_t)(nbr.lin = va_arg(args, long)));
	if ((t == d || t == D || t == i) && m == ll)
		return ((intmax_t)(nbr.lli = va_arg(args, long long)));
	if ((t == d || t == D || t == i) && m == hh)
		return ((intmax_t)(char)(nbr.chr = va_arg(args, int)));
	if ((t == d || t == D || t == i) && m == j)
		return ((nbr.inm = va_arg(args, intmax_t)));
	return (0);
}

char			*cvt_snbr(t_conv c, va_list args)
{
	intmax_t	nbr;
	char		*res;
	int			range;

	nbr = get_nbr(c.mod, c.type, args);
	range = find_range(nbr, c);
	if ((res = ft_itoa_pf(c, nbr, range)) == NULL)
		return (NULL);
	if (range < c.prec)
		if ((res = ft_chgprec(res, range, c.prec, get_pfxlen(res))) == NULL)
			return (NULL);
	return (res);
}
