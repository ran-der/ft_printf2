/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:40:47 by rvan-der          #+#    #+#             */
/*   Updated: 2016/10/14 16:55:09 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_dstrjoin(char const *s1, char const *s2)
{
	char	*new;

	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (s1);
	if ((new = (char*)malloc(sizeof(char) * \
					(ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	new = ft_strcpy(new, s1);
	new = ft_strcat(new, s2);
	ft_strdel(s1);
	ft_strdel(s2);
	return (new);
}

char		*ft_dstrnjoin(char const *s1, char const *s2, size_t n)
{
	char	*new;

	if (s1 == NULL && s2 != NULL)
	{
		if ((new = (char*)malloc(sizeof(char) * 2)) == NULL)
			return (NULL);
		return (new = ft_strncpy(new, s2, 1));
	}
	if (s2 == NULL)
		return (s1);
	if ((new = (char*)malloc(sizeof(char) * (ft_strlen(s1) +\
						n + 1))) == NULL)
		return (NULL);
	new = ft_strcpy(new, s1);
	new = ft_strncat(new, s2, n);
	ft_strdel(s1);
	return (new);
}
