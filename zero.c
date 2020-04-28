/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:46:27 by jiglesia          #+#    #+#             */
/*   Updated: 2020/04/28 16:52:55 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(t_flags x)
{
	int sum;

	sum = 0;
	if (!x.minus)
		sum += ft_intwidth(x, 1);
	if (x.precision)
		sum += ft_intprecision(x, 1);
	sum += write(1, "%", 1);
	if (x.minus)
		sum += ft_intwidth(x, 1);
	return (sum);
}

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

int	ft_p0(t_flags x)
{
	int a;

	a = 0;
	if (!x.minus)
		while (x.width-- > 3)
			a += write(1, " ", 1);
	a += write(1, "0x0", 3);
	if (x.minus)
		while (x.width-- > 3)
			a += write(1, " ", 1);
	return (a);
}

int	ft_snull(t_flags x)
{
	int a;

	a = 0;
	if (x.precision > 0 || !x.point)
	{
		if (!x.minus)
		{
			if (x.point)
			{
				if (x.precision > 6)
					while (x.width-- > 6)
						a += write(1, " ", 1);
				else
					while (x.width-- > x.precision)
						a += write(1, " ", 1);
			}
			else
				while (x.width-- > 6)
					a += write(1, " ", 1);
		}
		if (x.precision)
			a += write(1, "(null)", (x.precision > 6) ? 6 : x.precision);
		else
			a += write(1, "(null)", 6);
		if (x.minus)
		{
			if (x.point)
			{
				if (x.precision > 6)
					while (x.width-- > 6)
						a += write(1, " ", 1);
				else
					while (x.width-- > x.precision)
						a += write(1, " ", 1);
			}
			else
				while (x.width-- > 6)
					a += write(1, " ", 1);
		}
	}
	else
		while (x.width--)
			a += write(1, " ", 1);
	return (a);
}
