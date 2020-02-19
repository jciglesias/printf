/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:25:15 by jiglesia          #+#    #+#             */
/*   Updated: 2020/02/19 22:44:42 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlength(int a)
{
	int i;

	i = (a < 0) ? 1 : 0;
	while (a)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int	ft_intwidth(t_flags x, int a)
{
	int	dif;
	int sum;

	dif = x.width;
	dif -= (ft_intlength(a) > x.precision) ?
		ft_intlength(a) : x.precision;
	dif -= (ft_intlength(a) > x.precision) ? 0 : a < 0;
	sum = dif;
	while (dif-- > 0)
		ft_putchar((x.zero && !x.minus && !x.precision) ? '0' : ' ');
	return ((sum > 0) ? sum : 0);
}

int	ft_intprecision(t_flags x, int a)
{
	int	dif;
	int	sum;

	sum = 0;
	dif = x.precision - ft_intlength(a);
	if (a < 0)
		dif++;
	sum = dif;
	while (dif-- > 0)
		ft_putchar('0');
	return ((sum > 0) ? sum : 0);
}
