/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:46:27 by jiglesia          #+#    #+#             */
/*   Updated: 2020/02/18 22:20:07 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_void0(t_flags x)
{
	int a;

	a = 0;
	if (!x.minus)
		while (x.width-- > 5)
			a += write(1, " ", 1);
	a += write(1, "(nil)", 5);
	if (x.minus)
		while (x.width-- > 5)
			a += write(1, " ", 1);
	return (a);
}

int	ft_snull(t_flags x)
{
	int a;

	a = 0;
	if (x.precision > 5 || !x.point)
	{
		if (!x.minus)
			while (x.width-- > 6)
				a += write(1, " ", 1);
		a += write(1, "(null)", 6);
		if (x.minus)
			while (x.width-- > 6)
				a += write(1, " ", 1);
	}
	else
		while (x.width--)
			a += write(1, " ", 1);
	return (a);
}
