/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:59:26 by rvan-der          #+#    #+#             */
/*   Updated: 2016/10/18 17:15:16 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*add_space(t_conv c, char *res, int len)
{
	char		*new;
	int			i;

	if ((new = (char*)malloc(sizeof(char) * c.field + 1)) == NULL)
		return (NULL);
	i = -1;
	if (c.min)
	{
		while (++i < len)
			new[i] = res[i];
		while (i < c.field)
			new[i++] = ' ';
	}
	else
	{
		while (i < c.field - len)
			new[i++] = ' ';
		i -= 1;
		while (++i <= c.field)
			new[i] = res[i - c.field + len];
	}
	new[i] = '\0';
	free(res);
	return (new);
}		

static char		*ft_padding(t_conv c, char *res, int len)
{
	int			pfx;

	if (ft_check_tp(c.mod, c.type) > 1 && c.zero && !c.min && c.prec < 0)
	{
		pfx = get_pfxlen(res);
		return (ft_chgprec(res, len, c.field - pfx, pfx));
	}
	return (add_space(c, res, len));
}

char			*ft_write_conv(t_conv c, va_list args, t_cvtfct **ctab)
{
	char		*res;
	int			len;

	if ((res = (ctab[c.mod][c.type])(c, args)) == NULL)
		return (NULL);
	if (c.prec > -1 && (c.type == s || c.type == S))
		if ((res = ft_dstrsub(res, 0, c.prec)) == NULL)
			return (NULL);
	if (c.field > (len = ft_strlen(res)))
		res = ft_padding(c, res, len);
	return (res);
}
