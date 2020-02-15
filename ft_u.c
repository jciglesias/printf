/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia </var/spool/mail/jiglesia>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:36:00 by jiglesia          #+#    #+#             */
/*   Updated: 2020/02/15 19:12:17 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ulength(unsigned int a)
{
	int i;

	i = 0;
	while (a /= 10)
		i++;
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
