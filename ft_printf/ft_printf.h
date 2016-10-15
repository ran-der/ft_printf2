/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:34:41 by rvan-der          #+#    #+#             */
/*   Updated: 2016/10/13 22:19:33 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum			e_type
{
	s = 0,
	S,
	p,
	d,
	D,
	i,
	o,
	O,
	u,
	U,
	x,
	X,
	c,
	C
}						t_type;

typedef enum			e_mod
{
	hh = 0,
	h,
	l,
	ll,
	j,
	z
}						t_mod;

typedef union			u_val
{
	int					din; 1
	unsigned			uin; 2
	short				hin; 3
	unsigned short		hun; 4
	long				lin; 5
	unsigned long		lun; 6
	long long			lli; 7
	unsigned long long	llu; 8
	char				chr; 9
	unsigned char		uch; 10
	char				*str; 11
	wchar_t				wch; 12
	wchar_t				*wst; 13
	intmax_t			inm; 14
	uintmax_t			unm; 15
	size_t				szt; 16
}						t_val;

typedef struct			s_conv
{
	t_type				type;
	t_mod				mod;
	int					field;
	int					prec;
	int					altern;
	int					zero;
	int					min;
	int					plus;
	int					space;
}						t_conv;

typedef					char* (*t_traduce)(t_conv*, va_list);

int						ft_printf(const char *format, ...);
int						ft_isvalid_type(char c);
int						ft_isvalid_flag(char c);
char					*ft_strnjoin(char const *s1, char const *s2, size_t n);
int						ft_count_dig(char *str);
char					*ft_parse(char **format, char *str, va_list args, \
									char ***ttab);
t_conv					*ft_init_conv(void);
int						ft_get_conv(char *format, t_conv **conversion, int i,\
									int indicator);
int						ft_get_mod(char *format, t_conv **conv, int i);
int						ft_get_flag(char *format, t_conv **conv, int i);

#endif
