/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 19:22:47 by jiglesia          #+#    #+#             */
/*   Updated: 2020/05/11 19:22:48 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ulength(unsigned int a)
{
	int i;

	if (!a)
		return (1);
	i = 0;
	while (a)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int	ft_uprecision(t_flags x, unsigned int a)
{
	int	dif;
	int	sum;

	sum = 0;
	dif = x.precision - ft_ulength(a);
	sum = dif;
	while (dif-- > 0)
		ft_putchar('0');
	return ((sum > 0) ? sum : 0);
}
