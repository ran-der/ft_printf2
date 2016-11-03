/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_wtxt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 19:03:00 by rvan-der          #+#    #+#             */
/*   Updated: 2016/10/24 19:59:45 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*cvt_wtxt(t_conv c, va_list args)
{
	int			ch;
	char		*ret;
	wchar_t		*tmp;

	if (c.type == s || c.type == S)
	{
		tmp = va_arg(args, wchar_t*);
		return (rewrite(tmp));
	}
	ch = va_arg(args, int);
	if ((ret = (char*)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	ret[2] = 
	ret[1] = '\0';
	return (ret);
}
