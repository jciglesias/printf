/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uxX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia </var/spool/mail/jiglesia>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:32:13 by jiglesia          #+#    #+#             */
/*   Updated: 2020/02/22 22:07:56 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xwidth(t_flags x, char *str)
{
	int	dif;
	int	sum;

	dif = x.width;
	dif -= (ft_strlen(str) > x.precision) ?	ft_strlen(str) : x.precision;
	sum = dif;
	while (dif-- > 0)
		ft_putchar((x.zero && !x.minus && !x.point) ? '0' : ' ');
	return ((sum > 0) ? sum : 0);
}

int	ft_xprecision(t_flags x, char *str)
{
	int     dif;
	int     sum;

	dif = x.precision - ft_strlen(str);
	sum = dif;
	while (dif-- > 0)
		ft_putchar('0');
	return ((sum > 0) ? sum : 0);
}

int	ft_xX(t_flags x, char *str)
{
	int sum;
	int i;

	i = 0;
	sum = 0;
	if (x.point && !x.width && !x.precision && str[0] == '0')
	{
		free(str);
		return (0);
	}
	if (!x.minus)
		sum += ft_xwidth(x, str);
	if (x.precision)
		sum += ft_xprecision(x, str);
	if (x.point && !x.precision && str[0] == '0')
		sum += write(1, " ", 1);
	else
		while (str[i])
			ft_putchar(str[i++]);
	sum += i;
	if (x.minus)
		sum += ft_xwidth(x, str);
	free(str);
	return (sum);
}

int	ft_uwidth(t_flags x, unsigned int a)
{
	int	dif;
	int	sum;

	dif = x.width;
	dif -= (ft_ulength(a) > x.precision) ? ft_ulength(a) : x.precision;
	sum = dif;
	while (dif-- > 0)
                ft_putchar((x.zero && !x.minus && !x.point) ? '0' : ' ');
	return ((sum > 0) ? sum : 0);
}

int	ft_u(t_flags x, unsigned int a)
{
	int sum;

	sum = 0;
	if (x.point && !x.precision && !x.width && !a)
		return (sum);
	if (!x.minus)
		sum += ft_uwidth(x, a);
	if (x.precision)
		sum += ft_uprecision(x, a);
	if (x.point && !x.precision && !a)
		sum += write(1, " ", 1);
	else
		sum += flag_u(a);
	if (x.minus)
		sum += ft_uwidth(x, a);
	return (sum);
}
