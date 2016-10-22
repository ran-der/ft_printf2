/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:40:47 by rvan-der          #+#    #+#             */
/*   Updated: 2016/10/18 17:12:53 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_check_tp(int y, int x)
{
	if (x == 1 || x == 13 || ((!x || x == 12) && y > 2 && y < 5))
		return (0);
	if ((x == 0 || x == 12) && (y < 3 || y > 4))
		return (1);
	if (y < 6 && x > 2 && x < 6)
		return (2);
	return (3);
}

char		*ft_dstrsub(char *str, unsigned int start, int len)
{
	char	*sub;

	if (len >= 0)
	{
		if ((sub = (char*)malloc(sizeof(char) * len + 1)) == NULL)
			return (NULL);
		sub = ft_strncpy(sub, str + start, len + 1);
		free(str);
		return (sub);
	}
	return (NULL);
}

char		*ft_dstrjoin(char *s1, char *s2)
{
	char	*new;

	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (s1);
	if ((new = (char*)malloc(sizeof(char) * \
					(ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	new = ft_strcpy(new, (const char*)s1);
	new = ft_strcat(new, (const char*)s2);
	ft_strdel(&s1);
	ft_strdel(&s2);	return (new);
}

char		*ft_dstrnjoin(char *s1, char *s2, size_t n)
{
	char	*new;

	if (s1 == NULL && s2 != NULL)
	{
		if ((new = (char*)malloc(sizeof(char) * n + 1)) == NULL)
			return (NULL);
		return (new = ft_strncpy(new, s2, n + 1));
	}
	if (s2 == NULL)
		return (s1);
	if ((new = (char*)malloc(sizeof(char) * (ft_strlen(s1) +\
						n + 1))) == NULL)
		return (NULL);
	new = ft_strcpy(new, (const char*)s1);
	new = ft_strncat(new, (const char*)s2, n);
	ft_strdel(&s1);
	return (new);
}
