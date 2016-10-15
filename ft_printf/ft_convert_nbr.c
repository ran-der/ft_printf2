/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016 10/05 18:31:54 by rvan-der          #+#    #+#             */
/*   Updated: 2016/10/05 19:48:15 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_nbr(t_val v, t_conv c, char ***ttab)
{
	intmax_t	nbr;

	nbr = 0;
	nbr = (ft_strcmp(ttab[c.mod][c.type], "din") ? nbr : (intmax_t)(val.din));
	nbr = (ft_strcmp(ttab[c.mod][c.type], "hin") ? nbr : (intmax_t)(val.hin));
	nbr = (ft_strcmp(ttab[c.mod][c.type], "chr") ? nbr : (intmax_t)(val.chr));
	nbr = (ft_strcmp(ttab[c.mod][c.type], "lin") ? nbr : (intmax_t)(val.lin));
	nbr = (ft_strcmp(ttab[c.mod][c.type], "lli") ? nbr : (intmax_t)(val.lli));
	nbr = (ft_strcmp(ttab[c.mod][c.type], "szt") ? nbr : (intmax_t)(val.szt));
	nbr = (ft_strcmp(ttab[c.mod][c.type], "inm") ? nbr : (intmax_t)(val.inm));
	return (nbr);
}

char		*nbr_conversion(t_val val, t_conv conv, char **ttab)
{
	intmax_t	nbr;

	nbr = get_nbr(val, conv, ttab);
	
