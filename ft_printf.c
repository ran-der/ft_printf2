/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:35:42 by rvan-der          #+#    #+#             */
/*   Updated: 2016/10/24 17:45:00 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_del_ctab(t_cvtfct **ctab)
{
	int				i;

	i = -1;
	while (++i < 7)
		free(ctab[i]);
	free(ctab);
}

static t_conv		*ft_new_conv(void)
{
	t_conv			*conversion;

	if ((conversion = (t_conv*)malloc(sizeof(t_conv))) == NULL)
		return (NULL);
	conversion->mod = 0;
	conversion->type = 0;
	conversion->field = 0;
	conversion->prec = -1;
	conversion->altern = 0;
	conversion->zero = 0;
	conversion->min = 0;
	conversion->plus = 0;
	conversion->space = 0;
	return (conversion);
}

static char			*ft_parse(char **format, char *str, va_list args,\
							t_cvtfct **ctab)
{
	t_conv			*conversion;
	char			*tmp;
	int				i;

	if (**format == '%' && *(++(*format)) != '%')
	{
		if ((conversion = ft_new_conv()) == NULL)
			return (NULL);
		if ((i = ft_get_conv(*format, &conversion, 0, 0)) == 0)
			return (ft_dstrnjoin(str, (--(*format)), 1));
		if ((tmp = ft_write_conv(*conversion, args, ctab)) == NULL)
			return (NULL);
		*format += i;
		return (ft_dstrjoin(str, tmp));
	}
	return (ft_dstrnjoin(str, ((*format)++), 1));
}

static t_cvtfct		**get_ctab(void)
{
	t_cvtfct		**ctab;
	int				i;

	if ((ctab = (t_cvtfct**)malloc(sizeof(t_cvtfct*) * 7)) == NULL)
		return (NULL);
	i = -1;
	while (++i < 7)
		if ((ctab[i] = (t_cvtfct*)malloc(sizeof(t_cvtfct) * 14)) == NULL)
			return (NULL);
	i = -1;
	while (++i < 98)
	{
		//if (ft_check_tp(i / 14, i % 14) == 0)
		//	ctab[i / 14][i % 14] = &cvt_wtxt;
		if (ft_check_tp(i / 14, i % 14) == 1)
			ctab[i / 14][i % 14] = &cvt_txt;
		if (ft_check_tp(i / 14, i % 14) == 2)
			ctab[i / 14][i % 14] = &cvt_snbr;
		if (ft_check_tp(i / 14, i % 14) == 3)
			ctab[i / 14][i % 14] = &cvt_unbr;
	}
	return (ctab);
}

int					ft_printf(const char *format, ...)
{
	va_list			args;
	char			*res;
	char			*form;
	t_cvtfct		**ctab;
	int				ret;

	if (format == NULL || (ctab = get_ctab()) == NULL)
		return (-1);
	res = NULL;
	form = (char*)format;
	va_start(args, format);
	while (*form != '\0')
		if ((res = ft_parse(&form, res, args, ctab)) == NULL)
			return (-1);
	va_end(args);
	write(1, res, (ret = ft_strlen(res)));
	ft_strdel(&res);
	ft_del_ctab(ctab);
	return (ret);
}
