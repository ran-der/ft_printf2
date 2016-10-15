/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:59:26 by rvan-der          #+#    #+#             */
/*   Updated: 2016/10/14 16:55:13 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_padding(char *str, char *res, t_conv *conv)
{
	int			i;
	int			len;

	i = 0;
	len = ft_strlen(res);
	if (conv->min)
	{
		while (i < len)
			str[i] = res[i++];
		while (i < conv->field)
			str[i++] = ' ';
		str[i] = '\0';
	}
	else
	{
		while (i < conv->field - len)
			str[i++] = ((conv->zero && conv->prec < 0) ||\
					ft_ischartype(conv) ? '0' : ' ');
		while (i <= conv->field)
			str[i] = res[i++ - conv->field + len];
		str[i] = '\0';
	}
	return (str);
}

char		*ft_get_base(t_type t)
{
	if (t == o || t == O)
		return ("01234567");
	if (t == x)
		return ("0123456789abcdef");
	if (t == X || t == p)
		return ("0123456789ABCDEF");
	return ("0123456789");
}

int			ft_data_tp(t_mod m, t_type t, int **ttab)
{
	if (t == s || t == S || t == c || t == C)
		return (0);
	if (ttab[m][t] == 15 || !(ttab[m][t] % 2))
		return (1);
	return (-1);
}

char		*ft_write_conv(t_conv *conv, va_list args, int **ttab)
{
	char		*res;
	int			dtp;
	t_val		val;

	if ((dtp = ft_data_tp(conv->mod, conv->type, ttab)) == 0)
		res = ft_convert_txt(conv, ttab, args);
	else
	{
		(dtp < 0 ? val.inm : val.unm) = \
										va_arg(args, (dtp < 0 ? intmax_t : uintmax_t));
		res = ft_convert_nbr(val, conv, ttab, ft_get_base(conv->type));
	}
	if (ft_strlen(res) < conv->field)
		res = ft_padding(res, conv);	
	return (res);
}
