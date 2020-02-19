/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia </var/spool/mail/jiglesia>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:04:37 by jiglesia          #+#    #+#             */
/*   Updated: 2020/02/19 12:10:19 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	initflags(t_flags x)
{
	x.zero = 0;
	x.minus = 0;
	x.width = 0;
	x.wstar = 0;
	x.precision = 0;
	x.pstar = 0;
	x.point = 0;
	return (x);
}

t_flags flgs(t_flags x, char *flags, int ***i)
{
	while (flags[***i] && ft_countchr(flags[***i], "0-"))
	{
		if (flags[(***i)++] == '0')
			x.zero = 1;
		else
			x.minus = 1;
	}
	return (x);
}

t_flags	fwidth(t_flags x, char *flags, int ***i)
{
	x.width = ft_atoi(&flags[***i]);
	while (flags[***i] >= '0' && flags[***i] <= '9')
		(***i)++;
	if (flags[***i] == '*')
		x.wstar = 1;
	(***i) += x.wstar;
	return (x);
}

t_flags	fprecision(t_flags x, char *flags, int ***i)
{
	if (flags[***i] == '.')
	{
		x.point = 1;
		x.precision = ft_atoi(&flags[++(***i)]);
		while (flags[***i] >= '0' && flags[***i] <= '9')
			(***i)++;
		if (flags[***i] == '*')
			x.pstar = 1;
		(***i) += x.pstar;
	}
	return (x);
}

t_flags	saveflags(char *flags, int **i, va_list ap)
{
	t_flags x;

	(**i)++;
	x = initflags(x);
	x = flgs(x, flags, &i);
	x = fwidth(x, flags, &i);
	if (x.wstar)
		x.width = va_arg(ap, int);
	if (x.width < 0)
		x.minus = 1;
	x.width = (x.width > 0) ? x.width : -x.width;
	x = fprecision(x, flags, &i);
	if (x.pstar)
		x.precision = va_arg(ap, int);
	x.precision = (x.precision > 0) ? x.precision : 0;
	x.convertion = flags[(**i)++];
	return (x);
}
