/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_wtxt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 19:03:00 by rvan-der          #+#    #+#             */
/*   Updated: 2016/11/04 21:06:03 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*rewrite(t_conv c, wchar_t *wstr, unsigned short short *masks)
{
	char		*tmp;
	char		*ret;
	int			bytes;
	int			chars;
	int			i;
	
	if (wstr == NULL)
		return (NULL);
	chars = 0;
	bytes = 0;
	i = 0;
	while (*((unsigned short short*)(wstr + i)) != 0)
	{
		while



char			*cvt_wtxt(t_conv c, va_list args)
{
	wchar_t		ch[2];
	wchar_t		*tmp;

	if (c.type == s || c.type == S)
	{
		tmp = va_arg(args, wchar_t*);
		return (rewrite(tmp));
	}
	wch[0] = va_arg(args, wchar_t);
	wch[1] = '\0';
	return (rewrite(wch));
}
