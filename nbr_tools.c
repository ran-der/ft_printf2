/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 17:46:58 by rvan-der          #+#    #+#             */
/*   Updated: 2016/10/24 17:54:01 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*get_base(t_type t)
{
	if (t == o || t == O)
		return ("01234567");
	if (t == x)
		return ("0123456789abcdef");
	if (t == X || t == p)
		return ("0123456789ABCDEF");
	return ("0123456789");
}

int					get_pfxlen(char *str)
{
	if (*str == ' ' || *str == '+' || *str == '-')
		return (1);
	if (*str == '0' && (str[1] == 'x' || str[1] == 'X'))
		return (2);
	return (0);
}

char				*ft_chgprec(char *res, int range, int prec, int pfx)
{
	char			*new;
	int				i;
	int				j;

	if ((new = (char*)malloc(sizeof(char) * prec + pfx + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < pfx)
	{
		new[i] = res[i];
		i++;
	}
	while (i < prec + pfx - (range - pfx))
		new[i++] = '0';
	j = pfx;
	while (j < range + pfx)
		new[i++] = res[j++];
	new[i] = '\0';
	free(res);
	return (new);
}
