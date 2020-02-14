/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_cspdu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:52:20 by jiglesia          #+#    #+#             */
/*   Updated: 2020/02/14 00:23:49 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_c(t_flags x, char c)
{
	int	a;
	int sum;

	a = x.width - 1;
	sum = (a > 0) ? a : 0;
	if (!x.minus)
		while (a-- > 0)
			ft_putchar(' ');
	sum += write(1, &c, 1);
	if (x.minus)
		while (a-- > 0)
			ft_putchar(' ');
	return (sum);
}

int		flag_s(t_flags x, char *s)
{
	int i;
	int	a;
	int sum;

	i = 0;
	a = x.width - ft_strlen(s);
	sum = (a > 0) ? a : 0;
	if (!x.minus)
		while (a-- > 0)
			ft_putchar(' ');
	while (s[i])
		ft_putchar(s[i++]);
	if (x.minus)
		while (a-- > 0)
			ft_putchar(' ');
	sum += i;
	return (sum);
}

int		flag_di(int d)
{
	int i;

	i = 0;
	ft_putnbr(d);
	if (d < 0)
		i++;
	while (d /= 10)
		i++;
	return (i);
}

int		flag_u(unsigned int u)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (u)
	{
		str = ft_realloc(str, 1);
		str[i++] = u % 10;
		u /= 10;
	}
	str[i] = 0;
	j = i;
	while (--i >= 0)
		ft_putchar(str[i]);
	return (j);
}
