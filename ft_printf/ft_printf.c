/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:35:42 by rvan-der          #+#    #+#             */
/*   Updated: 2016/10/05 19:48:17 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_write_conv_err(char c)
{
	write(2, "invalid conversion : \"%", 22);
	write(2, &c, 1);
	write(2, "\"\n", 1);
	return (NULL);
}

t_conv		*ft_new_conv(void)
{
	t_conv		*conversion;

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

char		*ft_parse(char **format, char *str, va_list args, \
			char ***ttab)
{
	t_conv		*conversion;
	char		*tmp;
	int			i;

	if (**format == '%' && *(++(*format)) != '%')
	{
		if ((conversion = ft_new_conv()) == NULL)
			return (NULL);
		if ((i = ft_get_conv(*format, &conversion, 0, 0)) == 0 )
			return (NULL);
		if ((tmp = ft_write_conv(conversion, args, ttab)) == NULL)
			return (NULL);
		*format += i;
		return (ft_dstrjoin(str, tmp));
	}
	return (ft_dstrnjoin(str, (*format)++, 1));
}

char		***get_ttab(void)
{
	char		***tab;
	int			i;
	//int			fd;
	//char		buff[4];

	if ((tab = (char***)malloc(sizeof(char**) * 6)) == NULL)
		return (NULL);
	i = -1;
	while (++i < 6)
		if ((tab[i] = (char**)malloc(sizeof(char*) * 14)) == NULL)
			return (NULL);
}


int			ft_printf(const char *format, ...)
{
	va_list		args;
	char		*str;
	char		*form;
	char		***ttab;

	if (format == NULL || (ttab = get_ttab()) == NULL)
		return (-1);
	str = NULL;
	form = (char*)format;
	va_start(args, format);
	while (*form != '\0')
		if ((str = ft_parse(&form, str, args, ttab)) == NULL)
			return (-1);
	va_end(args);
	write(1, str, (ft_strlen(str)));
	return (ft_strlen(str));
}
